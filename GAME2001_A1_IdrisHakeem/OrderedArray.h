#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class OrderedArray: public Array<T>
{
public:
	// Constructor
	OrderedArray(int size, int growBy = 2) : Array<T>(size, growBy){}
	// Destructor
	~OrderedArray()
	{
		std::cout << "OrderedArrary Destructor\n";
		if (Array<T>::m_array != NULL)
		{
			delete[] Array<T>::m_array;
			Array<T>::m_array = NULL;
		}
	}
	// Insertion -- Big O = O(N)
	int push(T val)
	{
		assert(Array<T>::m_array != NULL);
		if (Array<T>::m_numElements >= Array<T>::m_maxSize)
		{
			Array<T>::Expand();
		}
		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < Array<T>::m_numElements; i++)
		{
			if (Array<T>::m_array[i] > val)
			{
				break;
			}
			// Exits out of the function when the value pushed is the same as a value stored in the array (m_array)
			else if (Array<T>::m_array[i] == val) // This returns an error value to reject the duplicate value
			{
				return -1;
			}
		}
		// Step 2: Shift everything to the right of the indexx forward by one
		for (k = Array<T>::m_numElements; k > i; k--) // Moving backwards through the array starting at m_numElements
		{
			Array<T>::m_array[k] = Array<T>::m_array[k - 1];
		}
		// Step 3: Insert val to index
		Array<T>::m_array[i] = val;

		Array<T>::m_numElements++;
		return i;
	}
	// Searching -- Binary Search -- Big O = O(log N)
	int search(T searchKey)
	{
		assert(Array<T>::m_array != NULL);
		// Helper variables
		int lowerBound = 0;
		int upperBound = Array<T>::m_numElements - 1;
		int current = 0;

		while (1)	// <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of Bitwise operations.
			// The (>> 1) means divide by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for
			if (Array<T>::m_array[current] == searchKey)
			{
				// Found the item in the middle of the array. Return the index of the item
				return current;
			}
			// Step 2: Check that we've searched the whole array. Can't find the item
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				// Step 3: Check which half of the array the value is in searchKey value's range
				if (Array<T>::m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}
		return -1;
	}
};