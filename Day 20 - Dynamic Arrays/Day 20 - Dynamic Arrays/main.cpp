#include <iostream>
#include "dynamic_arrays_header.h"

int main() 
{
	Dynamic_Array<char> arry;

	for (size_t i = 65; i < 91; i++)
	{
		arry.push_back(i);
	}

	arry.insert('6', 6);

	return 0;
}