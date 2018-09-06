//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  dfs.cpp
//  @brief GraphAlgo::dfs class defination
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
//  @brief DFS algorithm pseudocode
//
//         Algorithm DFS(G, v):
//           Input: A graph G and a vertex v of G
//           Output: A labeling of the edges in the connected component of v 
//                   as discovery edges and back edges
//           label v as visited
//           for all edges e in v.incidentEdges() do
//               if edge e is unvisited then
//                   w ← e.opposite(v)
//                   if vertex w is unexplored then
//                       label e as a discovery edge
//                       recursively call DFS(G, w)
//                   else
//                       label e as a back edge
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#include "dfs.hpp"

using namespace GraphAlgo;



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
dfs_traversal( const vertex& v )
{
	vertices::const_iterator it = m_neighborhood[v].begin();
	for ( ; it != m_neighborhood[v].end(); ++it ) 
	{
		if ( ! m_visit[*it] ) 
		{
			m_visit[*it] = true ;
			g_out.add_edge(v, *it);
			dfs_traversal(*it);
		}
	}
}


dfs::
dfs( const graph& g, const vertex& v )
{
	g_in = g;

	m_vertices = g.get_vertices();
	m_neighborhood = g.get_neighborhood();

	vertices::const_iterator it = m_vertices.begin();
	for( ; it != m_vertices.end(); ++it ) 
	{
		m_visit.insert( visit::value_type(*it, false) );
	}
	
	m_visit[v] = true;      
	dfs_traversal(v);
}


dfs::
~dfs() {

}

