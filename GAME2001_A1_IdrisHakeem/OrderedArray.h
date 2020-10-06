#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class OrderedArray: public Array<T>
{
public:
	OrderedArray(int size, int growBy = 1) : Array(size), m_array(NULL) {}
		//m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	/*{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}*/
	~OrderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
private:
	// Insertion -- Big O is O(N)
	void push(T val) override
	{
		assert(m_array != NULL);
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}
		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}
		// Step 2: Shift everything to the right of the indexx forward by one
		for (k = m_numElements; k > i; k--) // Moving backwards through the array starting at m_numElements
		{
			m_array[k] = m_array[k - 1];
		}
		// Step 3: Insert val to index
		m_array[i] = val;

		m_numElements++;
		return i;
	}

	int search(T searchKey) override
	{
		assert(m_array != NULL);
		// Helper variables
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)	// <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of Bitwise operations.
			// The (>> 1) means divide by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for
			if (m_array[current] == searchKey)
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
				if (m_array[current] < searchKey)
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
private:
};