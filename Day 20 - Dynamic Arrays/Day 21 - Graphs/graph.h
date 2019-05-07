#pragma once
#include <vector>
#include "node.h"
#include "edge.h"

template<typename T>

class graph
{
	graph<T>();

	~graph()
	{
		for (auto node : m_nodes)
		{
			delete node;
		}

		for (auto edge : m_edge)
		{
			delete edge;
		}
	}

	node<T>* create_node()
	{
		node<T>* new_node = new node<T>();
		m_nodes.push_back(new_node);
		return new_node;
	}

	edge* create_edge(node<T>* a_node_A, node<T>* a_node_B)
	{
		edge<T>* new_edge = new edge<T>(a_node_A, a_node_B);
		m_edge.push_back(new_edge);
		return new_edge;
	}

	void remove_node(node<T>* a_node)
	{
		for (auto edge : a_node->get_edges())
		{
			remove_edge(edge);
		}

		auto iter = std::find(m_nodes.begin(), m_nodes.end(), a_node);
		delete(*iter);
		m_nodes.erase(iter);
	}

	void remove_edge(node<T>* a_edge)
	{
		a_edge->m_nodes[0]->remove_edge(a_edge);
		a_edge->m_nodes[1]->remove_edge(a_edge);

		auto iter = std::find(m_edges.begin(), m_edges.end(), a_edge);
		delete (*iter);
		m_edges.erase(iter);
	}

private:
	std::vector<node<T>*> m_nodes;
	std::vector<node<T>*> m_edges;
};