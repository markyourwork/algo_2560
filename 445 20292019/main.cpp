//Padraic Burns and yien wu 
//Project 3b
//Define the main fucntion and execute program.
//definitions for findMatches() and search() are included 

#include "Grid.h"
#include "Dictionary.h"

void findMatches(Dictionary d, Grid g)
//Prints the mtching words in the dictionary that can be found in the grid
{
	//Set max length of each list
	int maxLength = g.getNumRows();
	int row, column, dictResult;
	std::string strToBuild = "";
	matrix<std::string> mat = g.getMat();

	//store strings from the grid matching dictionary
	vector<std::string> foundStrings;

	//store row index of found string in matrix
	vector<int> foundRowIndex;

	//store column index of found string in matrix
	vector<int> foundColIndex;

	//store start letter of found string
	vector<string> foundStartLetter;

	//store dictionary index of found string
	vector<int> foundDictIndex;
	
	for (int i = maxLength-1; i >= 0; i--)
	{
		for (int j = maxLength-1; j >= 0; j--)
		{
			//Reset strToBuild to blank string
			//Reset row and column to origin character
			strToBuild = "";
			row = i;
			column = j;
			//Up direction
			//Count only goes up to maxLength characters away from the origin character
			for (int count = 0; count < maxLength; count++)
			{
				strToBuild += mat[row][column];
				dictResult = d.binarySearch(strToBuild);
				if (dictResult != -1)
				{
					foundStrings.push_back(strToBuild);
					foundRowIndex.push_back(row);
					foundColIndex.push_back(column);
					foundDictIndex.push_back(dictResult);
					foundStartLetter.push_back(mat[i][j]);
				}

				//Change row only
				row--;
				//Upper edge case
				if (row == -1)
					row = maxLength - 1;
				std::cout << "#1 " << row << std::endl; //here
			}

			//Reset strToBuild to blank string
			//Reset row and column to origin character
			strToBuild = "";
			row = i;
			column = j;

			//Down direction
			for (int count = 0; count < maxLength; count++)
			{
				strToBuild += mat[row][column];
				dictResult = d.binarySearch(strToBuild);
				if (dictResult != -1)
				{
					foundStrings.push_back(strToBuild);
					foundRowIndex.push_back(row);
					foundColIndex.push_back(column);
					foundDictIndex.push_back(dictResult);
					foundStartLetter.push_back(mat[i][j]);
				}

				//Change row only
				row++;
				//Lower edge case
				if (row == maxLength)
					row = 0;
				std::cout << "#2 " << row << std::endl; //here
			}
			
			//Reset strToBuild to blank string
			//Reset row and column to origin character
			strToBuild = "";
			row = i;
			column = j;

			//Left direction
			for (int count = 0; count < maxLength; count++)
			{
				strToBuild += mat[row][column];
				dictResult = d.binarySearch(strToBuild);
				if (dictResult != -1)
				{
					foundStrings.push_back(strToBuild);
					foundRowIndex.push_back(row);
					foundColIndex.push_back(column);
					foundDictIndex.push_back(dictResult);
					foundStartLetter.push_back(mat[i][j]);
				}

				//Change column only
				column--;
				//Left edge case
				if (column == -1)
					column = maxLength - 1;
				std::cout << "#3 " << column << std::endl; //here

			}

			//Reset strToBuild to blank string
			//Reset row and column to origin character
			strToBuild = "";
			row = i;
			column = j;

			//Right direction
			for (int count = 0; count < maxLength; count++)
			{
				strToBuild += mat[row][column];
				dictResult = d.binarySearch(strToBuild);
				if (dictResult != -1)
				{
					foundStrings.push_back(strToBuild);
					foundRowIndex.push_back(row);
					foundColIndex.push_back(column);
					foundDictIndex.push_back(dictResult);
					foundStartLetter.push_back(mat[i][j]);
				}
				//Change column only
				column++;
				//Right edge 
				if (column == maxLength)
					column = 0;
				std::cout << "#4 " << column << std::endl;

			}

			//Reset strToBuild to blank string
			//Reset row and column to origin character
			strToBuild = "";
			row = i;
			column = j;

			//Up left direction
			for (int count = 0; count < maxLength; count++)
			{
				strToBuild += mat[row][column];
				dictResult = d.binarySearch(strToBuild);
				if (dictResult != -1)
				{
					foundStrings.push_back(strToBuild);
					foundRowIndex.push_back(row);
					foundColIndex.push_back(column);
					foundDictIndex.push_back(dictResult);
					foundStartLetter.push_back(mat[i][j]);
				}
				//Change row and column
				row--;
				column--;
				//Left edge 
				if (column == -1)
					column = maxLength - 1;
				//Upper edge 
				if (row == -1)
					row = maxLength - 1;

				std::cout << "#5 " << column << " " << row << std::endl; //here

			}

			//Up right direction
			for (int count = 0; count < maxLength; count++)
			{
				strToBuild += mat[row][column];
				dictResult = d.binarySearch(strToBuild);
				if (dictResult != -1)
				{
					foundStrings.push_back(strToBuild);
					foundRowIndex.push_back(row);
					foundColIndex.push_back(column);
					foundDictIndex.push_back(dictResult);
					foundStartLetter.push_back(mat[i][j]);
				}
				//Change row and column
				row--;
				column++;
				//Right edge 
				if (column == maxLength)
					column = 0;
				//Upper edge 
				if (row == -1)
					row = maxLength - 1;

				std::cout << "#6 " << column << " " << row << std::endl; //here

			}

			//Down right direction
			for (int count = 0; count < maxLength; count++)
			{
				strToBuild += mat[row][column];
				dictResult = d.binarySearch(strToBuild);
				if (dictResult != -1)
				{
					foundStrings.push_back(strToBuild);
					foundRowIndex.push_back(row);
					foundColIndex.push_back(column);
					foundDictIndex.push_back(dictResult);
					foundStartLetter.push_back(mat[i][j]);
				}
				//Change row and column
				row++;
				column++;
				//Right edge case
				if (column == maxLength)
					column = 0;
				//Lower edge case
				if (row == maxLength)
					row = 0;

				std::cout << "#7 " << column << " " << row << std::endl; //here

			}

			//Down left direction
			for (int count = 0; count < maxLength; count++)
			{
				strToBuild += mat[row][column];
				dictResult = d.binarySearch(strToBuild);
				if (dictResult != -1)
				{
					foundStrings.push_back(strToBuild);
					foundRowIndex.push_back(row);
					foundColIndex.push_back(column);
					foundDictIndex.push_back(dictResult);
					foundStartLetter.push_back(mat[i][j]);
				}

				//Change row and column
				row++;
				column--;
				//Left edge
				if (column == -1)
					column = maxLength - 1;
				//Lower edge
				if (row == maxLength)
					row = 0;

				std::cout << "#8 " << column << " " << row << std::endl; //here
			}
		}
	}

	//Prints the list of found words
	for (int i = 0; i < foundStrings.size(); i++)
	{
		if (foundStrings[i].length() >= 5)
		{
			cout << "Found word: " << foundStrings[i]
				<< " in matrix position " << foundRowIndex[i] << ", "
				<< foundColIndex[i]
				<< " of starting letter: " << foundStartLetter[i]
				<< " and at dictionary index " << foundDictIndex[i] << endl;
		}
	}
}

void search()
//Reads the names of the grid file from the keyboard
//Prints out all words from the word list 
{
	Dictionary d("dictionary-sorted.txt");
	string gridFileName; // user can put in a file name

	std::cout << "Please enter the name of the grid file." << std::endl;
	std::cin >> gridFileName;
	//If user input lacks .txt extension, append it
	if (gridFileName.find(".txt") == std::string::npos)
		gridFileName.append(".txt");

	Grid g(gridFileName);
	findMatches(d, g);
}


int main()
//Main function
{
	search();
}