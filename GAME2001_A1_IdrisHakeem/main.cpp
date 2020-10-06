#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include "Array.h"
using namespace std;

int main()
{
	cout << "Recursive Binary Search Example" << endl;
	OrderedArray<int> array(3);
	Array<int>* arrayptr = &array;

	arrayptr->push(43);
	arrayptr->push(6);
	arrayptr->push(23);
	arrayptr->push(94);
	arrayptr->push(17);
	arrayptr->push(83);
	arrayptr->push(44);
	arrayptr->push(28);

	// Test expansion of array
	/*array.push(43);
	array.push(6);
	array.push(23);
	array.push(94);
	array.push(17);
	array.push(83);
	array.push(44);
	array.push(28);*/

	cout << "Ordered array contents: ";

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << " " << array[i];
	}

	// Test the search
	cout << endl << endl;
	cout << "Search for 43 was found at index" << endl << endl;
	cout << arrayptr->search(43) << endl << endl;
	return 0;
}