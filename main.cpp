// Padraic Burns and Yien Wu
// Project 5

#include <iostream>
#include <limits.h>
#include "d_except.h"
#include <list>
#include <fstream>
#include "d_matrix.h"
#include "graph.h"
#include <queue>

using namespace std;

class maze
{
   public:
      maze(ifstream &fin);
      void print(int,int,int,int);
      bool isLegal(int i, int j);

      void setMap(int i, int j, int n);
      int getMap(int i, int j) const;
	  void findEdges(int i, int j, graph& g);
      void mapMazeToGraph(graph &g);
	  void findPathRecursive(graph &g, int nodeID);
	  bool isSolved(graph &g, int nodeID);
	  void findPathNonRecursive(graph &g, int startNode);
	  vector<int> findUnvisitedNeighbors(graph& g, int nodeID);
	  bool findShortestPath1(graph &g, int startNode);
	  bool findShortestPath2(graph &g, int startNode, int endNode);
	  void markAllNodesUnvisited(graph &g);
	  vector<int> findNodeCoords(graph& g, int nodeID);

   private:
      int rows; // number of rows in the maze
      int cols; // number of columns in the maze
	  bool mazeSolved = false;
      matrix<bool> value;
      matrix<int> map;      // Mapping from maze (i,j) 
	  stack<int> nodeStack;
};

void maze::markAllNodesUnvisited(graph& g)
{
	for (int i = 0; i < g.numNodes(); i++)
		g.unVisit(i);
}

void maze::setMap(int i, int j, int n)
// Set mapping from maze cell (i,j)
{
	map[i][j] = n;
}

int maze ::getMap(int i, int j) const
// Return mapping of maze cell (i,j) 
{
	return map[i][j];
}

bool maze::isSolved(graph &g, int nodeID)
// Returns true if the current nodeID is the exit node
// Exit node is bottom right corner
{
	if (nodeID == g.numNodes() - 1)
	{
		mazeSolved = true;
		return true;
	}
	else
		return false;
}

maze::maze(ifstream &fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct
{
   fin >> rows;
   fin >> cols;

   char x;

   value.resize(rows,cols);
   for (int i = 0; i <= rows-1; i++)
      for (int j = 0; j <= cols-1; j++)
      {
	 fin >> x;
	 if (x == 'O')
            value[i][j] = true;
	 else
	    value[i][j] = false;
      }

   map.resize(rows,cols);
}

void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze
{
   std::cout << endl;

   if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
      throw rangeError("Bad value in maze::print");

   if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
      throw rangeError("Bad value in maze::print");

   for (int i = 0; i <= rows-1; i++)
   {
      for (int j = 0; j <= cols-1; j++)
      {
	 if (i == goalI && j == goalJ)
	    std::cout << "*";
	 else
	    if (i == currI && j == currJ)
	       std::cout << "+";
	    else
	       if (value[i][j])
		  std::cout << " ";
	       else
		  std::cout << "X";
      }
      std::cout << endl;
   }
   std::cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) entry in the maze
{
   if (i < 0 || i > rows || j < 0 || j > cols)
      throw rangeError("Bad value in maze::isLegal");

   return value[i][j];
}

vector<int> maze::findNodeCoords(graph& g, int nodeID)
// Find corresponding i and j coords of passed nodeID
{
	vector<int> coords;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] == nodeID)
			{
				coords.push_back(i);
				coords.push_back(j);
				return coords;
			}
		}
	}
}

void maze::findEdges(int i, int j, graph& g)
// Finds all possible edges.
// Need to check for redundant edge creation (e.g. A->B & B->A)
{
	// Up direction
	if (i - 1 >= 0 && isLegal(i-1, j))
		g.addEdge(map[i][j], map[i - 1][j], 1);
	// Down direction
	if (i + 1 < rows && isLegal(i + 1, j))
		g.addEdge(map[i][j], map[i + 1][j], 1);
	// Left direction
	if (j - 1 >= 0 && isLegal(i, j - 1))
		g.addEdge(map[i][j], map[i][j - 1], 1);
	// Right direction
	if (j + 1 < cols && isLegal(i, j + 1))
		g.addEdge(map[i][j], map[i][j + 1], 1);
}

void maze::mapMazeToGraph(graph &g)
// Create a graph g that represents the legal moves in the maze m
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (value[i][j] == true)
				setMap(i, j, g.addNode(1));
			else
				//No route here
				map[i][j] = -1;
		}
	}

	// All possible nodes added.
	// Now add edges between nodes
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] != -1)
				findEdges(i, j, g);
		}
	}
}

vector<int> maze::findUnvisitedNeighbors(graph &g, int nodeID)
{
	vector<int> unvisitedNeighbors;

	for (int i = 0; i < g.numNodes(); i++)
	{
		if (!g.isVisited(i) && g.isEdge(nodeID, i))
			unvisitedNeighbors.push_back(i);
	}

	return unvisitedNeighbors;
}

void maze::findPathRecursive(graph& g, int nodeID)
// Find the correct path recursively
{
	vector<int> visitOrder;
	vector<int> nodeCoords;

	g.visit(nodeID);

	// Base case 1: no path exists
	if (!isSolved(g, nodeID) && g.allNodesVisited())
	{
		std::cout << "No path exists." << endl;
		return;
	}
	// Base case 2: maze solved
	else if (isSolved(g, nodeID))
	{
		std::cout << "Maze is solved!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < g.numNodes(); i++)
		{
			if (g.isEdge(nodeID, i) && !g.isVisited(i) && nodeID != i)
			{
				if (!isSolved(g, i))
				{
					findPathRecursive(g, i);
				}
			}
			if (mazeSolved)
			{
				visitOrder.push_back(i);
				// Print travel order
				for (int i = visitOrder.size()-1; i >=0;i--)
				{
					nodeCoords = findNodeCoords(g, visitOrder[i]);
					print(rows, cols, nodeCoords[0], nodeCoords[1]);
				}
				return;
			}
		}
	}
}

void maze::findPathNonRecursive(graph &g, int startNode)
// Use queue based nonrecursive method
{
	int v;
	vector<int> unvisitedNeighbors;
	vector<int> nodeCoords;
	vector<int> visitOrder;
	// Mark all vertcies as unvisited
	markAllNodesUnvisited(g);

	//Push start vertex into queue, mark as visited
	queue<int> q;
	q.push(startNode);
	g.visit(startNode);

	while (!q.empty())
	{
		v = q.front();
		unvisitedNeighbors = findUnvisitedNeighbors(g, v);

		for (int i = 0; i < unvisitedNeighbors.size(); i++)
		{
			g.visit(unvisitedNeighbors[i]);
			q.push(unvisitedNeighbors[i]); //Visit order
		}

		visitOrder.push_back(q.front());

		q.pop(); //Finish order

	}

	cout << visitOrder.back() << endl;

	// No path available
	if (g.allNodesVisited() && !isSolved(g, visitOrder.back()))
		cout << "No path available!"<<endl;
	else
	{
		// Print travel order
		for (int i = 0; i < visitOrder.size(); i++)
		{
			nodeCoords = findNodeCoords(g, visitOrder[i]);
				print(rows, cols, nodeCoords[0], nodeCoords[1]);
		}
	}
}

bool maze::findShortestPath1(graph &g, int startNode)
// Uses BFS to find shortest path through maze
{
	int v;
	vector<int> unvisitedNeighbors;
	vector<int> nodeCoords;
	vector<int> visitOrder;
	// Predecessor node vector
	vector<int> pred(g.numNodes(), -1);

    int n = g.numNodes();
	cout << "n: " << n << endl;
	// Mark all vertcies as unvisited
	markAllNodesUnvisited(g);

	// Push start vertex into queue, mark as visited
	queue<int> q;
	q.push(startNode);
	g.visit(startNode);

	while (!q.empty())
	{
		v = q.front();
		unvisitedNeighbors = findUnvisitedNeighbors(g, v);

		for (int i = 0; i < unvisitedNeighbors.size(); i++)
		{
			g.visit(unvisitedNeighbors[i]);
			q.push(unvisitedNeighbors[i]); //Visit order
			pred[unvisitedNeighbors[i]] = v;
		}

		visitOrder.push_back(q.front());

		q.pop(); //Finish order

	}

	cout << visitOrder.back() << endl;

	// No path available
	if (g.allNodesVisited() && !isSolved(g, visitOrder.back()))
	{
		cout << "No path available!" << endl;
		return false;
	}
	else
	{
		//Find shortest path using pred vector

		int currNode = visitOrder.back(); 

		vector<int> shortestPath;
		shortestPath.push_back(visitOrder.back());
		while (currNode != visitOrder.front())
		{
			shortestPath.push_back(pred[currNode]);
			currNode = pred[currNode];
		}

		// Print shortest path travel order
		cout << "The shortest path found using BFS: " << endl;
		for (int i = shortestPath.size()-1; i >= 0; i--)
		{
			nodeCoords = findNodeCoords(g, shortestPath[i]);
			print(rows, cols, nodeCoords[0], nodeCoords[1]);
		}

		return true;
	}

}

bool maze::findShortestPath2(graph& g, int startNode, int endNode)
// Uses Dijkstra's algorithm to find shortest path through maze
{
	cout << "Now in Dijkstra function" << endl;

    int n = g.numNodes();

    //Mark all nodes unvisited
	markAllNodesUnvisited(g);

	//Vector of nodes of shortest path
	vector<int> shortestPath(n);

	//Set shortest path for all vertices to infinity
    fill(shortestPath.begin(), shortestPath.end(), INT_MAX);

    //Priority queue for nodes
    priority_queue<int> pq;

    // print n
	cout << "n: " << n << endl;



	//Push all vertcies into priorityQueue
	for (int i =0; i<n; i++)
	{
        pq.push(i);
        //cout << "pq "<< pq.top()<<endl;
	}




	while (pq.empty() == false)
	{
       // int v = pq.pop()
        int v = pq.top();
        cout << "testing pq"<< endl;
        if (v == endNode)
        {
            cout << "shortest path found!"<< endl;
            return true;
        }
        else
        {
            shortestPath = findUnvisitedNeighbors(g, v);
            cout << "shortest path" << shortestPath[v] <<endl;
            for (int i=0; i<n; i++)
              {
                    shortestPath[i] = min(shortestPath[i],shortestPath[v]+g.getNodeWeight(v));
                    int minPath = shortestPath[i];
                    cout << "min path " << minPath <<endl;
                    if (shortestPath[i] < minPath)
                        shortestPath[0] = v;
              }
        }
	}


}

int main()
{
   char x;
   ifstream fin;

   // Read the maze from the file.
   string fileName = "maze1.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
	   graph g;
      while (fin && fin.peek() != 'Z')
      {
         maze m(fin);
		 m.mapMazeToGraph(g);

		 // Find shortest path 1
		 m.findShortestPath1(g, 0);
		 // Find shortest path 2
        cout << "Running Dijkstra!" << endl;
        m.findShortestPath2(g, 0, g.numNodes());
      }
   }
   catch (indexRangeError &ex)
   {
      cout << ex.what() << endl; exit(1);
   }
   catch (rangeError &ex)
   {
      cout << ex.what() << endl; exit(1);
   }
}
