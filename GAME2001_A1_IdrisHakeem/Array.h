#pragma once
#include <cassert>

template<class T>
class Array
{
public:
	// Constructor
	Array(int size, int growBy = 2) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize); // Explicitly allocating memory based on type T

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	virtual ~Array()
	{
		std::cout << "Arrary Destructor\n";
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	// Insertion -- Big O = O(N)
	virtual int push(T val) = 0;

	// Deletion
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
	// Remove an item given an index
	// (Almost) Brute-force execution -- Big-O = O(N)
	void remove(int index)
	{
		assert(m_array != NULL);
		if (index >= m_numElements)
		{
			return;
		}
		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	// Searching -- Binary Search -- Big O = O(log N)
	virtual int search(T searchKey) = 0;

	// Overloaded [] operator
	const T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}
	// Clear -- Big O = O(1)
	void clear()
	{
		m_numElements = 0;
	}
public:
	// Gets and Sets
	int GetSize() { return m_numElements; }
	int GetMaxSize() { return m_maxSize; }
	int GetGrowSize() { return m_growSize; }

	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
protected:
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}
		// Create the new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);
		// Copy the contents of the original array to the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		// Delete the old array
		delete[] m_array;
		// Clean up variable assignments
		m_array = temp;
		temp = NULL;
		m_maxSize += m_growSize;
		m_growSize+= 2; // Grow size increases every time Expand() is used

		return true;
	}
protected:
	// Variables
	T* m_array; // pointer to the beginning of the array
	int m_maxSize; // max size of the array
	int m_growSize; // amount the array can grow through expansion
	int m_numElements; // Number of items currently in my array
};