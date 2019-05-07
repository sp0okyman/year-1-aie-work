#pragma once
#include "node.h"

template <typename T>
class binary_tree
{
public:
	binary_tree<T>() {};
	~binary_tree() {};

	node<T>* m_root_node = nullptr;

	bool insert(const T& a_data)
	{
		if (!m_root_node)
		{
			m_root_node = new node<T>(a_data);
			return true;
		}

		bool inserted = false;

		node<T>* current_node = m_root_node;
		node<T>* previous_node = nullptr;

		while (!inserted)
		{
			if (a_data == current_node->get_data())
			{
				// data already exists
				inserted = false;
				return inserted;

			}
			if (a_data < current_node->get_data())
			{
				if (current_node->get_left()) // is there already a node?
				{
					current_node = current_node->get_left();
				}
				else // insert at null leaf by creating new node
				{
					current_node->set_left(new node<T>(a_data));
					current_node->get_left()->set_parent(current_node);
					inserted = true;
				}
			}
			else if (a_data > current_node->get_data())
			{
				if (current_node->get_right()) // is there already a node?
				{
					current_node = current_node->get_right();
				}
				else
				{
					current_node->set_right(new node<T>(a_data));
					current_node->get_right()->set_parent(current_node);
					inserted = true;
				}
			}
			if (!current_node)
			{
				current_node = new node<T>(a_data);
				current_node->set_parent(previous_node);
				return true;
			}
		}
		return inserted;
	}

	bool remove(const T& a_data)
	{
		if (!find(a_data)) { return false; }

		// look for location to insert
		bool found = false;
		node<T>* current_node = m_root_node;

		// find the data
		while (!found)
		{
			// compare and traverse
			if (a_data == current_node->m_data)
			{
				// data already existed
				found == true;
			}
			// left child check / insert
			else if (a_data < current_node->m_data)
			{
				if (current_node->get_left()) // is there already a node?
				{
					current_node = current_node->get_left();
				}
			}

			// right child check / insert
			else if (a_data > current_node->m_data) // is there already a node?
			{
				if (current_node->get_right())
				{
					current_node = current_node->get_right();
				}
			}
		}

		// if the current node has a right branch, then
		if (current_node->get_right)
		{
			// find the minimum value in the right branch by iterating down the left branch of 
			//the current node's right child until there are no more left branch nodes
			node<T>* search_node = current_node->get_right();
			while (search_node->get_left())
			{
				search_node = search_node->get_left();
			}
			// copy the value from this minimum node to the current node
			current_node->m_data = search_node->m_data;
			// find the minimum node's parent node
			// (the parent of the node you are deleting)
			// search_node->m_parent
			if (search_node == search_node->get_parent()->get_left())
			{
				// if you are deleting the parent's left node
				//	set this left child of the parent to the right
				//	child of the minimum node
				search_node->get_parent()->set_left() = search_node->get_right();
				if (search_node->get_right())
				{
					search_node->get_right()->get_parent() = search_node->get_parent();
				}
				delete search_node;
				search_node = nullptr;
			}
			else if (search_node == search_node->get_parent()->get_right())
			{
				// if you are deleting the parent's right node
				//	set the right child of the parent to
				//	the minimum node's right child
				search_node->get_parent()->set_right() = search_node->get_right();
				if (search_node->get_right) 
				{
					search_node->get_right()->set_parent() = search_node->get_parent();
				}
				delete search_node;
				search_node = nullptr;
			}
			else { std::cout << "Massive error in remove"; }

			return true;
		}
		else
		{
			//if we are deleting the root, the root becomes the left chile of the current node
			
			if (current_node == m_root_node)
			{
				if (m_root_node->get_left())
				{
					m_root_node = m_root_node->get_left();
					m_root_node->set_parent() = nullptr;
				}
				else
				{
					// last node?
					m_root_node = nullptr;
				}
			}
		// if the current node has no right branch
		// if we are deleting the parent's left child,
		//	set the left child of the parent to the left
		// child of the current node
		else if (current_node == current_node->get_parent()->get_left())
			{
				current_node->get_parent()->set_left() = current_node->get_left();
				current_node->get_left()->set_parent() = current_node->get_parent();
			}
		else if (current_node == current_node->get_parent->get_right)
			{
				current_node->get_parent()->set_right() = current_node->get_right();
				current_node->get_left()->set_parent() = current_node->get_parent();
			}
		}
	}

	bool find(const T& a_data)
	{
		if (!m_root_node) 
		{ 
			return false; // if there's no root node, there's no data
			std::cout << "There is no data.\n";
		} 
		
		bool found = false;
		node<T>* current_node = m_root_node;

		while (!found)
		{
			if (current_node->get_data() == a_data)
			{
				found = true;
				break;
			}

			if (current_node->get_data() > a_data)
			{
				if (current_node->get_left() != nullptr)
				{
					current_node->set_left(current_node);
				}
				else { return false; }
			}

			if (current_node->get_data() < a_data)
			{
				if (current_node->get_right() != nullptr)
				{
					current_node->set_right(current_node);
				}
				else { return false; }
			}
		}
	}
};