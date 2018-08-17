#include <iostream>
#include "graph.hpp"
#include "dfs.hpp"

typedef std::vector<graph> graphs;

class connectivity
{
private:
	graph g_in;
	graphs graphs_out;
	visit m_visit;
//	visit m_unvisited;
//	neighborhood m_neighborhood;

public:
	void connected_parts(graph&);
	bool is_connected();
	void initialize();
	connectivity(const graph&);
	~connectivity();
	graphs& operator() ();
};
