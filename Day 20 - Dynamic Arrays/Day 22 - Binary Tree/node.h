#pragma once
template <typename T>
class node
{
public:
	// constructor
	node(const T& a_data) : m_data(a_data){ }
	
	// destructor
	~node();             

	// checks if node has left/right child-nodes
	bool hasLeft() { return (m_left != nullptr); }
	bool hasRight() { return (m_right != nullptr); }

	// getters
	T get_data() { return m_data; }
	node* get_parent() { return m_parent; }
	node* get_left() { return m_left; }
	node* get_right() { return m_right; }

	// setters
	void set_data( T a_data ) { m_data = a_data; }
	void set_parent(node* a_node) { m_parent = a_node; }
	void set_left( node* a_node ) { m_left = a_node; }
	void set_right( node* a_node ) { m_right = a_node; }

	// declaration of variables
private:	
	T m_data;
	node<T>* m_parent = nullptr;
	node<T>* m_left = nullptr;
	node<T>* m_right = nullptr;
};