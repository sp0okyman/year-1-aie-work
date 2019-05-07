#include <iostream>
#include "linked_lists_header.h"

int main()
{
	// Making a new linked_list of float type, call it list_of_floats
	linked_list<float> *list_of_floats = new linked_list<float>();

	// Calling the functions to do stuff with list_of_floats
	list_of_floats->push_back( 1.0f );
	list_of_floats->push_front( 2.0f );
	list_of_floats->push_back(5.0f);
	list_of_floats->push_front(6.0f);
	list_of_floats->begin();
	list_of_floats->end();
	list_of_floats->count();
	list_of_floats->insert( 1 , 4.0f );
	list_of_floats->erase(2);
	list_of_floats->remove( 5.0f );
	list_of_floats->pop_back();
	list_of_floats->pop_front();
	list_of_floats->empty();
	list_of_floats->clear();
	list_of_floats->empty();

	node<float> *current_node = list_of_floats->m_start->m_next;
	while (current_node != list_of_floats->m_end) {

		std::cout << current_node->m_data << std::endl;
		current_node = current_node->m_next;
	}

	system("Pause");

	return 0;
}