//  File: Stack.h
//	Purpose: Header file for Stack.hpp
//  Project: MazeSolverStack
//  Author: Ryan Amaral
//  Created On: January 28, 2016

// based on Hal's Stack.h

#ifndef _STACK_H
#define _STACK_H

#include "StackNode.hpp"
#include <iostream>

// Codes to return from functions for feedback
enum StatusCode {success, underflow, overflow};

template <typename...> class Stack;

// stack for primitive
template <typename type> // use template to make it any type
class Stack<type>
{
private:
	StackNode<type>* _top; // need reference to top node (last node)

public:
	Stack<type>();
	~Stack<type>();

	StatusCode push(type data); // add top node
	StatusCode pop(); // delete top node
	type peek(); // see value of top node

	bool isEmpty(); // returns if stack is empty

	template <typename type2>
	friend std::ostream& operator<<(std::ostream& output, const Stack<type2>& stack);
};

// stack for pointer
template <typename typePtr> // use template to make it any type
class Stack<typePtr*>
{
private:
	StackNode<typePtr*>* _top; // need reference to top node (last node)

public:
	Stack<typePtr*>();
	~Stack<typePtr*>();

	StatusCode push(typePtr* data); // add top node
	StatusCode pop(); // delete top node
	typePtr* peek(); // see value of top node

	bool isEmpty(); // returns if stack is empty

	template <typename typePtr2>
	friend std::ostream& operator<<(std::ostream& output, const Stack<typePtr2*>& stack);
};

#endif