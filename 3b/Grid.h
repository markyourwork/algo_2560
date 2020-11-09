// YIEN WU and Padraic Burns 
// Project 3b
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
	int numRows=0;
	int numCols=0;
public:
	Grid(std::string fileName);
	matrix<std::string> getMat();
	int getNumRows();

};

#endif Grid_h