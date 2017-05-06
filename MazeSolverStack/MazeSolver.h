//  File: MazeSolver.h
//	Purpose: Header file for MazeSolver.cpp
//  Project: MazeSolverStack
//  Author: Ryan Amaral
//  Created On: January 29, 2016

#ifndef _MAZESOLVER_H
#define _MAZESOLVER_H

#include "Stack.hpp"

class MazeSolver
{
private:
	// the maze will be stored in a one dimensional array
	int _rowLength; // the length of each row, adding this is down one, sub is up one
	int _columnLength; // how many rows there are, for printing later
	int _totalChars; // the amount of chars to print
	char* _theCharsToPrint; // copy from chars input to print with path in
	bool* _isAvailable; // true if the space in the maze is not a wall
	bool* _haveIBeen; // true where the solver has already been
	Stack<int> _mazeStack; // stack of type in stores locations in path
public:
	MazeSolver();
	MazeSolver(std::string inFileName); // creates a maze from a passed in ifstream
	~MazeSolver();

	bool useMaze(std::string inFileName); // tries to use the maze in the ifstream, return success
	bool solveMaze(); // returns true if maze is solvable, and solves maze
	bool saveMazeSolution(std::string outFileName); // tries to save solution to file, returns success
};

#endif