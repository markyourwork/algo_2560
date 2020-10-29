//Padraic Burns and yien wu 
//Project 3a
//Grid class definition

#include "Grid.h"
#include <fstream>

Grid::Grid(std::string fileName)
//Read in fileName to be made into a Grid
//Store grid in a matrix
{
	ifstream fin(fileName);

	//Handle file read error
	if (!fin)
	{
		std::cerr << "Cannot open " << fileName << std::endl;
		return;
	}

	//Read in matrix numRows and numCols
	fin >> numRows >> numCols;
	//Resize strMat according to numRows and numCols
	strMat.resize(numRows, numCols);
	//Fill matrix with file data
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			fin >> strMat[i][j];
	}
}

int Grid::getNumRows()
{
	return numRows;
}

matrix<std::string> Grid::getMat()
//Returns strMat
{
	return strMat;
}