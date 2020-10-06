#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class UnorderedArray : public Array<T>
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) : Array(size) {}
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
	// Destructor
	~UnorderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
private:
	// Insertion -- Big-O is O(1)
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

	virtual int search(T val)
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
private:
};