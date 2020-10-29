//Padraic Burns and yien wu 
//Project 3a
//Header for Grid Class
#pragma once
#ifndef Grid_h
#define Grid_h

#include "d_matrix.h"
#include <string>

class Grid
{
private:
	matrix<std::string> strMat;
	int numRows;
	int numCols;
public:
	Grid(std::string fileName);
	matrix<std::string> getMat();
	int getNumRows();

};

#endif Grid_h