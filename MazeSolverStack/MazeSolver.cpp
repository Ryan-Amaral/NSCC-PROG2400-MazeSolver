//  File: MazeSolver.cpp
//	Purpose: The file that has functionality for solving a maze.
//  Project: MazeSolverStack
//  Author: Ryan Amaral
//  Created On: January 29, 2016

#include "MazeSolver.h"
#include <fstream>
#include <istream>

MazeSolver::MazeSolver() 
{
	_mazeStack = Stack<int>(); // create stack
}

/// Create maze and pass in file immediately.
MazeSolver::MazeSolver(std::string inFileName)
{
	useMaze(inFileName); // use maze file imediately
	_mazeStack = Stack<int>(); // create stack
}

MazeSolver::~MazeSolver() 
{
	delete[] _isAvailable;
	delete[] _haveIBeen;
}

/// Use the maze from the passed in file.
bool MazeSolver::useMaze(std::string inFileName)
{
	try
	{
		std::ifstream inFile;
		inFile.open(inFileName);

		// get the amount of lines in the file
		// starts at beginning of file and goes to end, looking for all \n
		int lineCount = std::count(std::istreambuf_iterator<char>(inFile),
			std::istreambuf_iterator<char>(), '\n') + 1;

		_columnLength = lineCount;

		inFile.seekg(inFile.beg); // set back to beggining of file

		int colCount = -1; // the amount of colums, char per row
		// get amount of chars in first row - 1
		char inChar;
		do
		{
			inChar = inFile.get();
			++colCount;
		} while (!(inChar == '\r' || inChar == '\n'));

		_rowLength = colCount;
		
		int totalLocations = colCount * lineCount; // the size of the arrays

		// create the booleans arrays
		_theCharsToPrint = new char[totalLocations]; // and char array
		_isAvailable = new bool[totalLocations];
		_haveIBeen = new bool[totalLocations];

		inFile.seekg(inFile.beg); // set back to beggining of file

		// assign values for where is available, and set all has been to false
		int i; // declare i here to get value after
		for (i = 0; i < totalLocations; i++)
		{
			inChar = inFile.get();

			// if not new line, add elements to array
			if (!(inChar == '\r' || inChar == '\n'))
			{
				_theCharsToPrint[i] = inChar;
				// open space
				if (inChar == ' ')
				{
					_isAvailable[i] = true;
				}
				// wall
				else if (inChar == '-' || inChar == '|' || inChar == '+')
				{
					_isAvailable[i] = false;
				}
				_haveIBeen[i] = false; // always not have been
			}
			// subtract one from i, to make up for unused char
			else
			{
				--i;
			}
		}
		_totalChars = i;

		inFile.close();

		return true;
	}
	catch (std::ifstream::failure)
	{
		return false; // something wrong with file
	}
	catch (...)
	{
		return false; // something wrong with file
	}
}

/// Solve the maze if there is useMaze has already been called.
bool MazeSolver::solveMaze()
{
	// start location is always _rowLength
	_mazeStack.push(_rowLength); // the starting node
	int curPos;
	bool canGoRight;
	bool canGoDown;
	bool canGoLeft;
	bool canGoUp;
	// keep looking until stack peek is at final location
	while (_mazeStack.peek() != (_totalChars - _rowLength - 1))
	{
		curPos = _mazeStack.peek();
		if (curPos == 2548)
		{
			curPos = _mazeStack.peek();
		}
		// right, down, left, up
		// never worry about out of bounds except for left of start

		// see if can go right
		if (_isAvailable[curPos + 1] && !_haveIBeen[curPos + 1])
		{
			canGoRight = true;
		}
		else
		{
			canGoRight = false;
		}

		// see if can go down
		if (_isAvailable[curPos + _rowLength] && !_haveIBeen[curPos + _rowLength])
		{
			canGoDown = true;
		}
		else
		{
			canGoDown = false;
		}

		// see if can go left
		// never worry about out of bounds except for left of start
		if (curPos != _rowLength)
		{
			if (_isAvailable[curPos - 1] && !_haveIBeen[curPos - 1])
			{
				canGoLeft = true;
			}
			else
			{
				canGoLeft = false;
			}
		}
		else
		{
			canGoLeft = false;
		}

		// see if can go up
		if (_isAvailable[curPos - _rowLength] && !_haveIBeen[curPos - _rowLength])
		{
			canGoUp = true;
		}
		else
		{
			canGoUp = false;
		}

		// look right
		if (canGoRight)
		{
			// add teh location to stack and leave bread crumbly
			_mazeStack.push(curPos + 1);
			_haveIBeen[curPos + 1] = true;
		}
		// look down
		else if (canGoDown)
		{
			// add teh location to stack and leave bread crumbly
			_mazeStack.push(curPos + _rowLength);
			_haveIBeen[curPos + _rowLength] = true;
		}
		// look left
		else if (canGoLeft)
		{
			// add teh location to stack and leave bread crumbly
			_mazeStack.push(curPos - 1);
			_haveIBeen[curPos - 1] = true;
		}
		// look up
		else if (canGoUp)
		{
			// add teh location to stack and leave bread crumbly
			_mazeStack.push(curPos - _rowLength);
			_haveIBeen[curPos - _rowLength] = true;
		}
		// pop stack if nothing is available (almost forgot this crucial part)
		else
		{
			_mazeStack.pop();
		}

		if (_mazeStack.isEmpty())
		{
			return false; // failure if stack empties
		}
	}

	return true;
}

/// Saves the solution to a file.
bool MazeSolver::saveMazeSolution(std::string outFileName)
{
	try
	{
		std::ofstream outFile;
		// open the file, and remove old contents
		outFile.open(outFileName, std::ios_base::trunc);

		// put the locations of stack into char array as '@'s
		while (!_mazeStack.isEmpty())
		{
			_theCharsToPrint[_mazeStack.peek()] = '@';
			_mazeStack.pop();
		}

		// print each char
		for (int i = 0; i < _totalChars; i++)
		{
			outFile.put(_theCharsToPrint[i]);
			// insert new line if at end of line
			if (i != 0 && ((i + 1) % (_rowLength) == 0))
			{
				outFile.put('\n');
			}
		}
		outFile.close();
		return true;
	}
	catch (std::ofstream::failure)
	{
		return false; // something wrong with file
	}
	catch (...)
	{
		return false; // something wrong with file
	}
}