#include <iostream>
#include "dynamic_arrays_header.h"

int main() 
{
	Dynamic_Array<char> arry;
	Dynamic_Array<char> arryTwo;

	for (size_t i = 65; i < 91; i++)
	{
		arry.push_back(i);
	}
	arryTwo.push_back('a');
	arryTwo.push_back('b');
	arryTwo.push_back('c');
	arryTwo.push_back('d');

	arry.insert('6', 6);
	arry.insert(arryTwo, 3);
	arry.remove(1);

	return 0;
}