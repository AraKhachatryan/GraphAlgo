#ifndef DFS_HPP
#define DFS_HPP

#include <map>
#include "graph.hpp"

typedef std::map<vertex, bool> visit;

class dfs
{
private:
	graph g_in;
	graph g_out;
	visit m_visit;
	
	vertices m_vertices;
	neighborhood m_neighborhood;
	
public:
	graph& operator() ();
	visit get_visit() const;
	void dfs_traversal(const vertex&);
	dfs(const graph&, const vertex&);
	~dfs();
};

#endif
