// YIEN WU and Padraic Burns 
// Project 3b
//Define the main fucntion and execute program.

#include "Grid.h"
#include "Dictionary.h"

void findMatches(Dictionary d, Grid g)
//Print all matching words in the dictionary that can be found in the grid
{
	//Set max length of each list
	int maxLength = g.getNumRows();
	int row, column, dictResult;
	std::string strToBuild="";
	matrix<std::string> mat = g.getMat();


	vector<std::string> foundStrings;
	vector<int> foundRowIndex;
	vector<int> foundColIndex;
	vector<string> foundStartLetter;
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
				std::cout << "#1 " << row << std::endl;
			}

			//Reset strToBuild to blank string
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
				std::cout << "#2 " << row << std::endl;
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
				std::cout << "#3 " << column << std::endl;

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
				//Right edge case
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
				//Left edge case
				if (column == -1)
					column = maxLength - 1;
				//Upper edge case
				if (row == -1)
					row = maxLength - 1;

				std::cout << "#5 " << column << " " << row << std::endl;

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
				//Right edge case
				if (column == maxLength)
					column = 0;
				//Upper edge case
				if (row == -1)
					row = maxLength - 1;

				std::cout << "#6 " << column << " " << row << std::endl;

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

				std::cout << "#7 " << column << " " << row << std::endl;

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
				//Left edge case
				if (column == -1)
					column = maxLength - 1;
				//Lower edge case
				if (row == maxLength)
					row = 0;

				std::cout << "#8 " << column << " " << row << std::endl;
			}
		}
	}

	//Print out list of found words
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

void search(int sortMethod)
//Read the names of the grid file from the keyboard
//Print out all words from the word list that can be found 
{
	
	Dictionary d("dictionary.txt");

	
	std::vector<std::string> list = d.getWordList();

	string gridFileName; //user input a file name

	//Ask for which crossword grid to search on
	std::cout << "Please enter name of the grid file." << std::endl;
	std::cin >> gridFileName;
	//If user input lacks .txt extension, append i
	if (gridFileName.find(".txt") == std::string::npos)
		gridFileName.append(".txt");

	//Choose which sort to use
	switch (sortMethod)
	{
		//Selection sort
	case 0:
		d.selectionSort();
		break;
		//Quick sort
	case 1:
		d.quickSort(0, d.getWordList().size() - 1);
		for (int i = 0; i < list.size(); i++)
		{
			std::cout << "quickSort complete " << list[i] << std::endl;
		}
		break;
		//Heap sort
	case 2:
		d.heapSort();
		break;
	default:
		std::cout << "Invalid selection! Quick sort selected by default."
			<< std::endl;
		d.quickSort(0, d.getWordList().size() - 1);
	}

	Grid g(gridFileName);
	findMatches(d, g);
}


int main()
{
	//Default sortMethod to quickSort()
	int sortMethod = 1;


	std::cout << "Please select a sort method. Enter '0' for "
		<< "selection sort, '1' for quick sort, or '2' for "
		<< "heap sort." << std::endl;
	std::cin >> sortMethod;

	search(sortMethod);
}