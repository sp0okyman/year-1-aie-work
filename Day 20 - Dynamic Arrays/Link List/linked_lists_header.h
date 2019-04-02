#pragma once
#include <iostream>
#ifndef LINKED_LISTS_HEADER
#define LINKED_LISTS_HEADER
// make a template variable of name t_template
template<typename t_template>
// make a node class
class node
{
public:
	// make pointers m_previous and m_next of node class
	// node class now has two pointers, previous and next to point to other shit
	// they are not capable of pointing to the m_start and m_end
	node* m_next;
	node* m_previous;
	// make t_template of m_data, so as to be able to use any variable type in the future to store into m_data
	t_template m_data;
};

template<typename t_template>
class linked_list
{
public:
	// make pointers of node class of generic variable (template) called m_start and m_end
	// they currently have no pointers (set to nullptr)
	node<t_template>* m_start = nullptr;
	node<t_template>* m_end = nullptr;
	// constructor
	linked_list<t_template>()
	{
		// creating two new nodes, m_start points to one and m_end points to the other
		m_start = new node<t_template>();
		m_end = new node<t_template>();

		// m_start's new node that was assigned to it, it's m_next now points to m_end's node
		m_start->m_next = m_end;
		// m_end's new node that was assigned to it, it's m_previous now points to m_start's node
		m_end->m_previous = m_start;
		
		std::cout << "Constructor called.\n";
	}
	// destructor
	~linked_list()
	{
		// new pointer called m_current, it's the same as the node that m_start's node's m_next pointer is pointing to
		node<t_template>* m_current = m_start->m_next;
		// while m_current is not pointing to the same node that m_end is pointing to...
		while (m_current != m_end)
		{
			// m_next is now pointing to what m_current's node's next is pointing to
			node<t_template>* next = m_current->m_next;
			// delete the node m_current is pointing at
			delete m_current;
			// m_current no longer points to a node
			m_current = nullptr;
			// m_current is now pointing to what next is pointing to
			m_current = next;
		}
		// delete the node that m_start is pointing to
		delete m_start;
		// m_start no longer points to a node
		m_start = nullptr;

		// delete the node that m_end is pointing to
		delete m_end;
		// m_end no longer points to a node
		m_end = nullptr;

		std::cout << "Destructor called.\n";
	}
	// function to add a new node at the start of the linked_list chain
	void push_front(const t_template& a_data)
	{
		// create a new pointer called current and point it towards a new node
		node<t_template>* current = new node<t_template>();
		// the node that current points to's data is assigned to what a_data is
		current->m_data = a_data;
		// the current node's m_previous pointer is pointing to the m_start's pointer's node
		current->m_previous = m_start;
		// the current node's m_next pointer is pointing to the node that m_start's m_next pointer is pointing to
		current->m_next = m_start->m_next;
		// the m_start node's m_next pointer is pointing to the node that current is pointing to
		m_start->m_next = current;
		// the current node's m_next pointer which is pointing to another node's m_previous pointer is now pointing to current's node
		current->m_next->m_previous = current;

		std::cout << "Push Front called.\n";
	}

	void push_back(const t_template& a_data)
	{
		// create a new pointer called current and point it towards a new node
		node<t_template>* current = new node<t_template>();
		// the node that current points to's data is assigned to what a_data is
		current->m_data = a_data;
		// the current node's m_previous pointer is pointing to m_end's m_previous pointer
		current->m_previous = m_end->m_previous;
		// the current node's m_nex pointer is pointing to the node m_end is pointing to
		current->m_next = m_end;
		// the m_end's m_previous pointer is pointing to the current node
		m_end->m_previous = current;
		// the m_end's m_previous' m_next pointer is now pointing to the current node
		current->m_previous->m_next = current;

		std::cout << "Push Back called.\n";
	}

	void insert(int a_iterator, t_template& a_data)
	{
		node<t_template>* current = m_start->m_next;
		int count = 0;

		while (count != a_iterator)
		{
			current = current->m_next;
			++count;
		}
		node<t_template>* node_pointer = new node<t_template>();
		node_pointer->m_data = a_data;
		node_pointer->m_previous = current;
		node_pointer->m_previous->m_next = node_pointer;
		node_pointer->m_next = current->m_next;
		node_pointer->m_next->m_previous = current;

		std::cout << "Insert called.\n";
	}

	int count()
	{
		node<t_template>* current = m_start->m_next;
		int m_count = 0;

		while (m_count != m_end)
		{
			current = current->m_next;
			++m_count;
		}
		return m_count;
		std::cout << "Count called. Count is at " << m_count << ".\n";
	}

	void erase(int a_iterator)
	{
		node<t_template>* current = m_start->m_next;
		int count = 0;

		while (count != a_iterator)
		{
			current = current->m_next;
			++count;
		}

		if (count == a_iterator)
		{
			current->m_previous->m_next = current->m_next;
			current->m_next->m_previous = current->m_previous;
			delete current;
		}
		std::cout << "Erase called.\n";
	}

	void remove(t_template a_value)
	{
		node<t_template>* current = m_start->m_next;

		while (current != m_end)
		{
			if (current->m_data == a_value) 
			{
				current->m_previous->m_next = current->m_next;
				current->m_next->m_previous = current->m_previous;
				node<t_template>* temp_pointer = current;
				current = current->m_next;
				delete temp_pointer;
			}
			else 
			{
				current = current->m_next;
			}
		}
	}

	void pop_front()
	{
		node<t_template>* temp_pointer;

		temp_pointer = m_start->m_next;
		m_start->m_next = temp_pointer->m_next;
		m_start->m_next->m_previous = m_start;
		delete temp_pointer;
	}

	void pop_back()
	{
		node<t_template>* temp_pointer;

		temp_pointer = m_end->m_previous;
		m_end->m_previous = temp_pointer->m_previous;
		m_end->m_previous->m_next = m_end;
		delete temp_pointer;
	}

	node<t_template> begin()
	{
		if (m_start->m_next != m_end)
		{
			return m_start->m_next;
		}
		else { return NULL; }
	}

	node<t_template> end()
	{
		return m_end->m_previous;
	}
};
#endif