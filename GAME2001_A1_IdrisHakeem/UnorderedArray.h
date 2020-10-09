#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class UnorderedArray: public Array<T>
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 2) : Array<T>(size, growBy){}
	// Destructor
	~UnorderedArray()
	{
		std::cout << "UnorderedArrary Destructor\n";
		if (Array<T>::m_array != NULL)
		{
			delete[] Array<T>::m_array;
			Array<T>::m_array = NULL;
		}
	}
	// Insertions
	// Fast insertion for UnorderedArray -- Big-O is O(1)
	int push(T val)
	{
		assert(Array<T>::m_array != NULL); // Debugging purposes
		if (Array<T>::m_numElements >= Array<T>::m_maxSize)
		{
			Array<T>::Expand();
		}
		// My array has space for the new value
		Array<T>::m_array[Array<T>::m_numElements] = val;
		int index = Array<T>::m_numElements;
		Array<T>::m_numElements++;
		return index;
	}
	// Searching (Linear search) -- Big O = O(N)
	int search(T val)
	{
		assert(Array<T>::m_array != NULL);

		// Brute force search
		for (int i = 0; i < Array<T>::m_numElements; i++)
		{
			if (Array<T>::m_array[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
};