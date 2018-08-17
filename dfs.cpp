#include "dfs.hpp"

graph& dfs::
operator() ()
{
	return g_out;	
}

visit dfs::
get_visit() const
{
	return m_visit;
}

void dfs::
dfs_traversal(const vertex& v)
{
	vertices::const_iterator it = m_neighborhood[v].begin();
	for ( ; it != m_neighborhood[v].end(); ++it ) {
		if( ! m_visit[*it] ) {
			m_visit[*it] = true ;
			g_out.add_edge(v, *it);
			dfs_traversal(*it);
		}
	}
}

dfs::
dfs(const graph& g, const vertex& v)
{
	g_in = g;

	m_vertices = g.get_vertices();
	m_neighborhood = g.get_neighborhood();

	vertices::const_iterator it = m_vertices.begin();
	for( ; it != m_vertices.end(); ++it) {
		m_visit.insert(visit::value_type(*it, false));
	}
	
	m_visit[v] = true;      
	dfs_traversal(v);
}

dfs::
~dfs() {

}

