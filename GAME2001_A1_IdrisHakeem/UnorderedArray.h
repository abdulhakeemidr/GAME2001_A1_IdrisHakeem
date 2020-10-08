#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class UnorderedArray: public Array<T>
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) : Array<T>(size, growBy){}
	// Destructor
	~UnorderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	// Insertions
	// Fast insertion for UnorderedArray -- Big-O is O(1)
	void push(T val)
	{
		assert(m_array != NULL); // Debugging purposes
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}
		// My array has space for the new value
		m_array[m_numElements] = val;
		m_numElements++;
	}
	// Searching (Linear search) -- Big O = O(N)
	int search(T val)
	{
		assert(m_array != NULL);

		// Brute force search
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
};