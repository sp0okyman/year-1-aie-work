#include <iostream>
#include "dynamic_arrays_header.h"

int main() 
{
	dynamic_array<char> d;

	for (size_t i = 65; i < 91; i++)
	{
		d.push(i);
	}

	d.insert('6', 6);

	return 0;
}