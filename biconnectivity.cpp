//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  biconnectivity.cpp
//  @brief GraphAlgo::biconnectivity class defination
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
//  @brief The Biconnectivity algorithm tests whether a graph is biconnected 
//         and and makes graph's biconnected components vector
//.............................................................................
//  @brief biconnectivity algorithm pseudocode:
//
//        PROCEDURE bicomponents(G)       // G = (V, E)
//
//        S = ø                           // S is the  edge stack
//        time ← 0
//        for each v ∈ V do
//           p[v] ← 0                     // unknown yet: NIL
//           dtime[v] ← time
//           b[v] ← n + 1
//        for each v ∈ V do
//           if dtime[v] = 0 then
//              biDFS(v)
//
//        PROCEDURE biDFS(v)              // discover  v
//
//        time ← time + 1
//        dtime[v] ← time
//        b[v] ← dtime[v]                 // no back  edge from descendant yet
//        for each neighbor w of v do     // first time  encounter  w
//           if dtime[w] = 0  then        // unknown  yet
//              push(v, w)
//              p[w] ← v
//              biDFS(w)                  // recursive  call
//              if b[w] ≥ dtime[v] then
//                 print “new biconnected component”
//                 repeat
//                    pop & print
//                 until (popped edge is (v, w))
//              else
//                 b[v] ← min{b[v], b[w]}
//           else if (dtime[w] < dtime[v] and w ≠ p[v]) then
//                                        // (v,w) is a back edge from v
//              push(v, w)
//              b[v] ← min{b[v], dtime[w]}
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#include "biconnectivity.hpp"
#include <iostream>
#include <algorithm>  // for std::find()

using namespace GraphAlgo;



bool biconnectivity::
is_biconnected() const
{
	if( graphs_out.size() == 1 ) {
		return true;
	} else {
		return false;
	}
}


void biconnectivity::
print_cutvertices() const
{
	cutvertices::const_iterator it = m_cutvertices.begin();
	for( ; it != m_cutvertices.end(); ++it )
	{
		std::cout << "cut vertex " << *it << std::endl;
	}
}


void biconnectivity::
new_bicomponent( const vertex& v, const vertex& w )
{
	int f, s ;
	graph gr;

	do {
		f = m_edge_stack.top().first;
		s = m_edge_stack.top().second;
		gr.add_edge(m_edge_stack.top());
		m_edge_stack.pop();
	} while ( ! ( f == v && s == w) );

	graphs_out.push_back(gr);
}


void biconnectivity::
biDFS( const vertex& v )
{
	++time;
	int children = 0;
	
	m_discovery_time[v] = time ;
	m_back[v] = m_discovery_time[v] ;
	
	vertices::const_iterator it = m_neighborhood[v].begin();
	for ( ; it != m_neighborhood[v].end(); ++it )
	{
		if ( m_discovery_time[*it] == 0 )
		{
			++children;
			m_edge_stack.push( edge(v, *it) );
			m_parent[*it] = v ;
			biDFS(*it);
			if ( m_back[*it] >= m_discovery_time[v] )
			{
				new_bicomponent(v, *it);
				if ( m_parent[v] != -1 ) {
					m_cutvertices.insert(v);
				}
			} else {
				m_back[v] = std::min(m_back[v], m_back[*it]) ;
			}
		} else if ( (m_discovery_time[*it] < m_discovery_time[v]) && (*it != m_parent[v]) ) {
			// (v, *it) is back edge
			m_edge_stack.push( edge(v, *it) );
			m_back[v] =  std::min(m_back[v], m_discovery_time[*it]);
		}
	}	
}


void biconnectivity::
bicomponents()
{
	time =  0;

	vertices::const_iterator it = m_vertices.begin();
	for ( ; it != m_vertices.end(); ++it)
	{
		m_parent.insert(parent::value_type( *it, -1 ));
		m_discovery_time.insert(discovery_time::value_type( *it, time ));
		m_back.insert(back::value_type( *it,  m_vertices.size()  + 1 ));
	}
	
	vertices::const_iterator it2 = m_vertices.begin();
	for ( ; it2 != m_vertices.end(); ++it2)
	{
		if( m_discovery_time[*it2] == 0) {
			biDFS(*it2);     // for each connected graph
		}
	}

}


biconnectivity::
biconnectivity( const graph& g )
{
	g_in = g;

	m_vertices = g_in.get_vertices();
	m_neighborhood = g_in.get_neighborhood();
		
	bicomponents();
}


biconnectivity::
~biconnectivity()
{

}


graphs& biconnectivity::
operator() ()
{
	return graphs_out;
}

