//  File: StackNode.hpp
//	Purpose: The node of a stack.
//  Project: MazeSolverStack
//  Author: Ryan Amaral
//  Created On: January 28, 2016

#include "StackNode.h"

//////////////////////////////////////////////////
// StackNode for primitive data
/////////////////////////////////////////////////

/// Create Stack node with data and the next.
template <typename type>
StackNode<type>::StackNode(type data, StackNode* next) : _data(data), _next(next) {}

/// Delete object if this node houses a pointer object
template <typename type>
StackNode<type>::~StackNode() 
{
	
}

/// Return the data in the node.
template <typename type>
type StackNode<type>::getData()
{
	return _data;
}

/// Sets the new data of this node.
template <typename type>
void StackNode<type>::setData(type data)
{
	_data = data;
}

/// Returns the next node in the stack.
template <typename type>
StackNode<type>* StackNode<type>::getNext()
{
	return _next;
}

/// Sets what this nodes next node is.
template <typename type>
void StackNode<type>::setNext(StackNode<type>* next)
{
	_next = next;
}


//////////////////////////////////////////////////
// StackNode for pointer data
/////////////////////////////////////////////////

/// Create Stack node with data and the next.
template <typename typePtr>
StackNode<typePtr*>::StackNode(typePtr* data, StackNode* next) : _data(data), _next(next) {}

/// Delete object if this node houses a pointer object
template <typename typePtr>
StackNode<typePtr*>::~StackNode()
{
	if (_data != nullptr)
	{
		delete _data;
	}
}

/// Return the data in the node.
template <typename typePtr>
typePtr* StackNode<typePtr*>::getData()
{
	return _data;
}

/// Sets the new data of this node.
template <typename typePtr>
void StackNode<typePtr*>::setData(typePtr* data)
{
	_data = data;
}

/// Returns the next node in the stack.
template <typename typePtr>
StackNode<typePtr*>* StackNode<typePtr*>::getNext()
{
	return _next;
}

/// Sets what this nodes next node is.
template <typename typePtr>
void StackNode<typePtr*>::setNext(StackNode<typePtr*>* next)
{
	_next = next;
}