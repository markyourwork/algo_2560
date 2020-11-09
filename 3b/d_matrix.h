// YIEN WU and Padraic Burns 
// Project 3b
#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <iostream>
#include "d_except.h"
#include <vector>


using namespace std;

template <typename T>
class matrix
{
  public:
   matrix(int numRows = 1, int numCols = 1, const T& initVal = T());
   // constructor.


   vector<T>& operator[] (int i);
   //index operator.
 

   const vector<T>& operator[](int i) const;
   //version for constant objects

   int rows() const;
   //return number of rows
   int cols() const;
   //return number of columns

   void resize(int numRows, int numCols);
   //modify the matrix size.
  

  private:
   int nRows, nCols;
   //number of rows and columns

   vector<vector<T> > mat;
   //matrix is implemented as nRows vectors (rows),
   //each having nCols elements (columns)
};

template <typename T>
matrix<T>::matrix(int numRows, int numCols, const T& initVal):
	nRows(numRows), nCols(numCols),
	mat(numRows, vector<T>(numCols,initVal))
{}

//non-constant version. 
//provides general access to matrix
//elements
template <typename T>
vector<T>& matrix<T>::operator[] (int i)
{
   if (i < 0 || i >= nRows)
      throw indexRangeError(
	 "matrix: invalid row index", i, nRows);

   return mat[i];
}

//constant version. 

template <typename T>
const vector<T>& matrix<T>::operator[] (int i) const
{
   if (i < 0 || i >= nRows)
      throw indexRangeError(
	 "matrix: invalid row index", i, nRows);

   return mat[i];
}

template <typename T>
int matrix<T>::rows() const
{
   return nRows;
}

template <typename T>
int matrix<T>::cols() const
{
   return nCols;
}

template <typename T>
void matrix<T>::resize(int numRows, int numCols)
{
   int i;
   
   
   if (numRows == nRows && numCols == nCols)
      return;

   //assign a new matrix size
   nRows = numRows;
   nCols = numCols;

   //resize to n rows
   mat.resize(nRows);

   //resize each row to have n columns
   for (i=0; i < nRows; i++)
      mat[i].resize(nCols);
}

#endif	
