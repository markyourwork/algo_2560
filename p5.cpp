// Padraic Burns and Yien Wu 
// Project 5a

#include <iostream>
#include <limits.h>
#include "d_except.h"
#include <list>
#include <fstream>
#include "d_matrix.h"
#include "graph.h"

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

   private:
      int rows; // # of rows in the maze
      int cols; // # of columns in the maze

      matrix<bool> value;
      matrix<int> map;      // Map from maze (i,j) 
};

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

maze::maze(ifstream &fin)
// Initializes a maze by reading values from fin
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
   cout << endl;

   if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
      throw rangeError("Bad value in maze::print");

   if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
      throw rangeError("Bad value in maze::print");

   for (int i = 0; i <= rows-1; i++)
   {
      for (int j = 0; j <= cols-1; j++)
      {
	 if (i == goalI && j == goalJ)
	    cout << "*";
	 else
	    if (i == currI && j == currJ)
	       cout << "+";
	    else
	       if (value[i][j])
		  cout << " ";
	       else
		  cout << "X";	  
      }
      cout << endl;
   }
   cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) 
{
   if (i < 0 || i > rows || j < 0 || j > cols)
      throw rangeError("Bad value in maze::isLegal");

   return value[i][j];
}

void maze::findEdges(int i, int j, graph& g)
// Finds all possible edges
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
// Create a graph g 
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

	// All possible nodes added
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

int main()
{
   char x;
   ifstream fin;
   
   // Read the maze from the file
   string fileName = "maze.txt";

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