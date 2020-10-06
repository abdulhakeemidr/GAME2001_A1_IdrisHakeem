#pragma once
#include <cassert>

template<class T>
class Array
{
public:
	// Constructor
	Array(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	virtual ~Array()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	// Insertions
	virtual void push(T val) = 0;
	// Deletion
	// Remove the last item inserted into the array
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
	// Search
	virtual int search(T searchVal) {};
	// Overload the [] operator
	T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}
	// Clear -- Big O = O(1)
	void clear()
	{
		m_numElements = 0;
	}

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

		return true;
	}
protected:
	T* m_array;
	int m_maxSize; 
	int m_growSize;
	int m_numElements;
};