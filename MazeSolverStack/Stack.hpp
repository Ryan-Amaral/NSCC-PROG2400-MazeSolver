//  File: Stack.hpp
//	Purpose: A stack data structure (First In Last Out).
//  Project: MazeSolverStack
//  Author: Ryan Amaral
//  Created On: January 28, 2016

// based on Hal's stack.cpp

#include "Stack.h"

//////////////////////////////////////////////////
// Stack for primitive data
/////////////////////////////////////////////////

/// Creates an empty stack.
template <typename type>
Stack<type>::Stack() : _top(nullptr) {}

/// Delete all remaining nodes.
template <typename type>
Stack<type>::~Stack()
{
	// delete nodes that aren't null
	while (_top != nullptr)
	{
		pop(); // pop will delete the node, and set top
	}
}

/// Puts a new node on top of the stack.
template <typename type>
StatusCode Stack<type>::push(type data)
{
	_top = new StackNode<type>(data, _top);
	return success;
}

/// Removes the top node from the stack.
template <typename type>
StatusCode Stack<type>::pop()
{
	// do nothing and report underflow if stack is empty
	if (_top == nullptr)
	{
		return underflow;
	}
	// delete the node, and make it's next the top
	else
	{
		StackNode<type>* temp = _top;
		_top = _top->getNext();
		delete temp;
		return success;
	}
}

/// Get the value from the top of the stack.
template <typename type>
type Stack<type>::peek()
{
	return _top->getData();
}

/// Returns true if the stack is empty
template <typename type>
bool Stack<type>::isEmpty()
{
	return _top == nullptr;
}

/// Overloaded output for primitives
// from hal's stack.cpp
template <typename type>
std::ostream& operator<<(std::ostream &output, const Stack<type> &stack)
{
	StackNode<type>* node = stack._top;

	while (node != nullptr)
	{
		output << node->getData() << std::endl;
		node = node->getNext();
	}

	return output;
}
template std::ostream& operator<<(std::ostream &output, const Stack<char> &stack); // need this to define output for char stack
template std::ostream& operator<<(std::ostream &output, const Stack<int> &stack); // need this to define output for int stack


//////////////////////////////////////////////////
// Stack for pointer data
/////////////////////////////////////////////////

/// Creates an empty stack.
template <typename typePtr>
Stack<typePtr*>::Stack() : _top(nullptr) {}

/// Delete all remaining nodes.
template <typename typePtr>
Stack<typePtr*>::~Stack()
{
	// delete nodes that aren't null
	while (_top != nullptr)
	{
		pop(); // pop will delete the node, and set top
	}
}

/// Puts a new node on top of the stack.
template <typename typePtr>
StatusCode Stack<typePtr*>::push(typePtr* data)
{
	_top = new StackNode<typePtr*>(data, _top);
	return success;
}

/// Removes the top node from the stack.
template <typename typePtr>
StatusCode Stack<typePtr*>::pop()
{
	// do nothing and report underflow if stack is empty
	if (_top == nullptr)
	{
		return underflow;
	}
	// delete the node, and make it's next the top
	else
	{
		StackNode<typePtr*>* temp = _top;
		_top = _top->getNext();
		delete temp;
		return success;
	}
}

/// Get the value from the top of the stack.
template <typename typePtr>
typePtr* Stack<typePtr*>::peek()
{
	return _top->getData();
}

/// Returns true if the stack is empty
template <typename typePtr>
bool Stack<typePtr*>::isEmpty()
{
	return _top == nullptr;
}

// not exactly sure how to do it with this
/// Overloaded output for objects
// from hal's stack.cpp
template <typename typePtr>
std::ostream& operator<<(std::ostream &output, const Stack<typePtr*> &stack)
{
	StackNode<typePtr*>* node = stack._top;

	while (node != nullptr)
	{
		output << node->getData() << std::endl;
		node = node->getNext();
	}

	return output;
}
template std::ostream& operator<<(std::ostream &output, const Stack<std::string*> &stack); // need this to define output for string stack
// put any other objects you want used here