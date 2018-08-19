#include "biconnectivity.hpp"
#include <iostream>
#include <algorithm>  // for std::find()

bool biconnectivity::
is_biconnected()
{
	if( graphs_out.size() == 1 ) {
		return true;
	} else {
		return false;
	}
}


void biconnectivity::
new_bicomponent(const vertex& v, const vertex& w)
{
	int f, s ;
	graph gr;

	do{
		f = m_edge_stack.top().first;
		s = m_edge_stack.top().second;
		gr.add_edge(m_edge_stack.top());
		m_edge_stack.pop();
	}while( ! ( f == v && s == w) );

	graphs_out.push_back(gr);
}


void biconnectivity::
biDFS(const vertex& v)
{
	time = time + 1 ;
	m_discovery_time[v] = time ;
	m_back[v] = m_discovery_time[v] ;
	
	vertices::const_iterator it = m_neighborhood[v].begin();
	for ( ; it != m_neighborhood[v].end(); ++it ) {
		if( m_discovery_time[*it] == 0 ) {
			m_edge_stack.push( edge(v, *it) );
			m_parent[*it] = v ;
			biDFS(*it);
			if( m_back[*it] >= m_discovery_time[v] ) {
				if ( m_parent[v] != 0  &&  std::find(m_cutvertices.begin(), m_cutvertices.end(), v) == m_cutvertices.end() ) {
					std::cout << "cut vertex " << v << std::endl;
					m_cutvertices.push_back(v);
				}
				new_bicomponent(v, *it);
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
	for( ; it != m_vertices.end(); ++it) {
		m_parent.insert(parent::value_type( *it, 0 ));
		m_discovery_time.insert(discovery_time::value_type( *it, time ));
		m_back.insert(back::value_type( *it,  m_vertices.size()  + 1 ));
	}
	
	vertices::const_iterator it2 = m_vertices.begin();
	for( ; it2 != m_vertices.end(); ++it2) {
		if( m_discovery_time[*it2] == 0) {
			biDFS(*it2);     // for each connected graph
		}
	}

}


biconnectivity::
biconnectivity(const graph& g)
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

