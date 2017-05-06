//  File: Source.cpp
//	Purpose: The main driver file for the maze solver.
//  Project: MazeSolverStack
//  Author: Ryan Amaral
//  Created On: January 28, 2016

#include "MazeSolver.h"
#include <conio.h>
#include <string.h>
#include <regex>
using namespace std;

// User must enter a full path to a text file
// From a project from y2s1, in c++ class
bool checkValidWindowsFilePath(char*& strIn, const string& extension)
{
	// the regex to match will add extension to end
	regex strRegex("[a-zA-Z\\.]:(\\/[a-zA-Z0-9_\\- !@#$%^&()+={}\\[\\]';.,~`]+)+\\." + extension);
	if (regex_match(strIn, strRegex))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char** argv)
{
	// the file names
	string inFileName;
	string outFileName;
	
	// wrong amount of arguments, exit
	if (argc < 3)
	{
		cout << "File path to txt input and output maze files required." << endl
			<< "ex: \"MazeSolverStack.exe f:/dir/infile.txt f:/dir/outfile.txt\"";
		_getch();
		return 0;
	}
	else if (argc > 3)
	{
		cout << "Too many argumants, only two are needed." << endl
			<< "File path to txt input and output maze files required." << endl
			<< "ex: \"MazeSolverStack.exe f:/dir/infile.txt f:/dir/outfile.txt\"";
		_getch();
		return 0;
	}
	// three arguments, first is just program name, next two are file
	else
	{
		// if file names/paths are invalid, exit now
		if (checkValidWindowsFilePath(argv[1], "txt") && checkValidWindowsFilePath(argv[2], "txt"))
		{
			inFileName = argv[1];
			outFileName = argv[2];
		}
		else
		{
			cout << "Invalid file path/name.";
			_getch();
			return 0;
		}
	}

	// files are fine create solver

	MazeSolver solver; // create the maze solving object

	// pass in the maze file
	if (!solver.useMaze(inFileName))
	{
		// exit if something wrong
		cout << "Unable to use maze file.";
		_getch();
		return 0;
	}

	// make it solve the maze
	if (!solver.solveMaze())
	{
		// exit if something wrong
		cout << "Unable to solve maze.";
		_getch();
		return 0;
	}

	// make it save the maze solution
	if (!solver.saveMazeSolution(outFileName))
	{
		// exit if something wrong
		cout << "Unable to save maze solution.";
		_getch();
		return 0;
	}
	else
	{
		// tell user maze saved
		cout << "Maze solution saved to \"" + outFileName + "\".";
	}

	_getch();
}