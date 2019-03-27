#include <iostream>
#include "linked_lists_header.h"

int main()
{
	linked_list<float> *list_of_floats = new linked_list<float>();

	list_of_floats->push(1.0f);
	list_of_floats->push(2.0f);
	list_of_floats->push(3.0f);
	list_of_floats->push(4.0f);
	list_of_floats->push(5.0f);
	list_of_floats->push_front(0.0f);

	return 0;
}