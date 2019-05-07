#include <crtdbg.h>

#include "graph.h"
#include <string>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	graph<std::string> m_graph;

	node<std::string>* node_A = m_graph.create_node("Solid Snake");
	node<std::string>* node_B = m_graph.create_node("Liquid Snake");
	node<std::string>* node_C = m_graph.create_node("Raiden");
	node<std::string>* node_D = m_graph.create_node("Solidus");
	node<std::string>* node_E = m_graph.create_node("Big Boss");

	m_graph.create_edge(node_A, node_B);
	m_graph.create_edge(node_A, node_A);

	return 0;
}