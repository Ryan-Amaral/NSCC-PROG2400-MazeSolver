//  File: StackNode.h
//	Purpose: Header file for StackNode.hpp
//  Project: MazeSolverStack
//  Author: Ryan Amaral
//  Created On: January 28, 2016

// based on Hal's StackNode.h

#ifndef _STACKNODE_H
#define _STACKNODE_H

template <typename...> class StackNode;

/// The class when it houses primitive data
template <typename type> // use template to make it any type
class StackNode<type>
{
private:
	type _data; // data is of whatever type the user wants
	StackNode<type>* _next; // the node one element below this one

public:
	StackNode();
	StackNode(type data, StackNode<type>* next);
	~StackNode();

	type getData();
	void setData(type data);

	StackNode<type>* getNext();
	void setNext(StackNode<type>* next);
};

/// The class when it houses pointer data.
template <typename typePtr> // use template to make it any type
class StackNode<typePtr*>
{
private:
	typePtr* _data; // data is of whatever type the user wants
	StackNode<typePtr*>* _next; // the node one element below this one

public:
	StackNode();
	StackNode(typePtr* data, StackNode<typePtr*>* next);
	~StackNode();

	typePtr* getData();
	void setData(typePtr* data);

	StackNode<typePtr*>* getNext();
	void setNext(StackNode<typePtr*>* next);
};

#endif