#ifndef BICONNECTIVITY_HPP
#define BICONNECTIVITY_HPP

#include <stack>
#include "graph.hpp"

typedef std::stack<edge> edge_stack;
typedef std::map<vertex, int> parent;
typedef std::map<vertex, int> discovery_time;
typedef std::map<vertex, int> back;

typedef std::vector<graph> graphs;


class biconnectivity
{
private:
	int time; 
	edge_stack m_edge_stack;
	parent m_parent;
	discovery_time m_discovery_time;
	back m_back;
	
	graph g_in;
	graphs graphs_out;
	vertices m_vertices;
	neighborhood m_neighborhood;
public:
	bool is_biconnected();
	void new_bicomponent(const vertex&, const vertex&);
	void biDFS(const vertex&);
	void bicomponents();
	biconnectivity(const graph&);
	~biconnectivity();
	graphs& operator() ();
};

#endif
