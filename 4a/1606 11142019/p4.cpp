// YIEN WU and Padraic Burns 
// Project 4a
//board class definition and main function

#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>

using namespace std;

typedef int ValueType; // The type of the value in a cell
const int Blank = -1;  // Indicates that a cell is blank
 
const int SquareSize = 3;  //  The number of cells in a small square


const int BoardSize = SquareSize * SquareSize; //usefull variable for use later

const int MinValue = 1;
const int MaxValue = 9;

int numSolutions = 0;

class board
// Store the entire Sudoku board
{
   public:
      board(int);
      void clear();
      void initialize(ifstream &fin);
	  void setCell(int i, int j, int k);
	  void resetCell(int i, int j);
      void printBoard();
	  void printConflicts();
      bool isBlank(int, int);
	  bool isSolved();
      ValueType getCell(int, int);
      
   private:


      matrix<ValueType> value;

	  matrix<bool> row, col, sq;
};

board::board(int sqSize)
   : value(BoardSize+1,BoardSize+1)
// Board constructor
{
   clear();
}

void board::clear()
// emptys the contents of the board, sets all to blank
{
   for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++)
      {
         value[i][j] = Blank;
      }
}

int squareNumber(int i, int j)
// Return the square number of cell i,j
{


	return SquareSize * ((i - 1) / SquareSize) + (j - 1) / SquareSize + 1;
}

void board::initialize(ifstream &fin)
// Read a Sudoku board from file 
{
   char ch;

   clear();

   //Resize 
   row.resize(BoardSize+1, BoardSize+1);
   col.resize(BoardSize+1, BoardSize+1);
   sq.resize(BoardSize+1, BoardSize+1);
   
   for (int i = 1; i <= BoardSize; i++)
   {
	   for (int j = 1; j <= BoardSize; j++)
	   {
		   fin >> ch;
		   if (ch != '.')
		   {
			   int val = ch - '0';
			   setCell(i, j, val);   
		   }
	   }
   }
}

void board::setCell(int i, int j, int val)
//Add value, update conflicts
{
	value[i][j] = val;
	//Update conflicts
	row[i][val] = true;
	col[j][val] = true;
	sq[squareNumber(i, j)][val] = true;		
}

void board::resetCell(int i, int j)
{
	//Get value at cell (i,j)
	int val = getCell(i, j);

	value[i][j] = Blank;

	row[i][val] = false;
	col[j][val] = false;
	sq[squareNumber(i, j)][val] = false;		
}

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class
{
   for (int i = 0; i < v.size(); i++)
      ostr << v[i] << " ";
   cout << endl;

   return ostr;
}

ValueType board::getCell(int i, int j)
// Returns the value stored in a cell.
{
   if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
      return value[i][j];
   else
      throw rangeError("bad value in getCell");
}

bool board::isBlank(int i, int j)
// Return true if cell i,j is blank, and false otherwise
{
   if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
      throw rangeError("bad value in setCell");

   return (getCell(i,j) == Blank);
}

bool board::isSolved()
//check if the board has been completely solved
{
	for (int i = 0; i < BoardSize; i++)
	{
		for (int j = 0; j < BoardSize; j++)
		{
			if (row[i][j] == false && col[i][j] == false && sq[i][j] == false)
				continue;
			else 
				return false;
		}
	}
	cout << "Solved board: " << endl;
	printBoard();
	return true;
}

void board::printBoard()
// Prints the current board
{
   for (int i = 1; i <= BoardSize; i++)
   {
      if ((i-1) % SquareSize == 0)
      {
         cout << " -";
	 for (int j = 1; j <= BoardSize; j++)
	    cout << "---";
         cout << "-";
	 cout << endl;
      }
      for (int j = 1; j <= BoardSize; j++)
      {
	 if ((j-1) % SquareSize == 0)
	    cout << "|";
	 if (!isBlank(i,j))
	    cout << " " << getCell(i,j) << " ";
	 else
	    cout << "   ";
      }
      cout << "|";
      cout << endl;
   }

   cout << " -";
   for (int j = 1; j <= BoardSize; j++)
      cout << "---";
   cout << "-";
   cout << endl;
}

void board::printConflicts()
{
	//Print row conflicts
	cout << "Row conflicts: " << endl;
	for (int i = 1; i <= BoardSize; i++)
	{
		for (int j = 1; j <= BoardSize; j++)
		{
			cout << row[i][j] << " ";
		}
		cout << endl;
	}

	//Print col conflicts
	cout << "Col conflicts: " << endl;
	for (int i = 1; i <= BoardSize; i++)
	{
		for (int j = 1; j <= BoardSize; j++)
		{
			cout << col[i][j] << " ";
		}
		cout << endl;
	}

	//Print sq conflicts
	cout << "Sq conflicts: " << endl;
	for (int i = 1; i <= BoardSize; i++)
	{
		for (int j = 1; j <= BoardSize; j++)
		{
			cout << sq[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
   ifstream fin;
   // Read the sample grid from the file
   string fileName = "sudoku1.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
      board b1(SquareSize);
      while (fin && fin.peek() != 'Z')
      {
	 b1.initialize(fin);
	 b1.printBoard();
	 b1.printConflicts();

	 if (b1.isSolved())
		 cout << "Board is solved." << endl;
	 else
		 cout << "Board is not solved." << endl;
      }
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }
}