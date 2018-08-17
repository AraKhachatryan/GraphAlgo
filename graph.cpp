#include "graph.hpp"
#include <iostream>
#include <algorithm>

void graph::
remove_vertex(vertex v)
{
	while( !m_neighborhood[v].empty() ) {
		remove_edge(v, m_neighborhood[v].back());
	}

	m_neighborhood.erase(v);	

	vertices::iterator v_it = find(m_vertices.begin(), m_vertices.end(), v);
	if(v_it != m_vertices.end()) {
		m_vertices.erase(v_it);
	}

}

void graph::
remove_edge(vertex s, vertex d)
{
	edges::iterator e_it = find(m_edges.begin(), m_edges.end(), edge(s, d));
	if(e_it != m_edges.end()) {
		m_edges.erase(e_it);
	}
	
	e_it = find(m_edges.begin(), m_edges.end(), edge(d, s));
	if(e_it != m_edges.end()) {
		m_edges.erase(e_it);
	}

	vertices::iterator v_it = find(m_neighborhood[s].begin(), m_neighborhood[s].end(), d);
	if ( v_it != m_neighborhood[s].end() ) {
		m_neighborhood[s].erase(v_it);
	}
	
	v_it = find(m_neighborhood[d].begin(), m_neighborhood[d].end(), s);
	if ( v_it != m_neighborhood[d].end() ) {
		m_neighborhood[d].erase(v_it);
	}
}

bool graph::
is_vertex_in_graph(const vertex& v) const
{
	vertices::const_iterator it = find(m_vertices.begin(), m_vertices.end(), v);
	if(it != m_vertices.end()) {
		return true;
	}else{
		return false;
	}
}

bool graph::
is_edge_in_graph(const edge& e) const
{
	edges::const_iterator it = m_edges.begin();
	for ( ; it != m_edges.end(); ++it ) {
			if ( it->first == e.first && it->second == e.second
					|| it->first == e.second && it->second == e.first ) {
			std::cout << __FUNCTION__ << ": Edge " << it->first << " and " << it->second << " already exist!" << std::endl;
			return true;
			}
	}
	return false;

}

bool graph::
is_edge_in_graph(const vertex& s, const vertex& d) const
{
	edges::const_iterator it = m_edges.begin();
	for ( ; it != m_edges.end(); ++it ) {
			if ( it->first == s && it->second == d
					|| it->first == d && it->second == s ) {
				std::cout << __FUNCTION__ << ": Edge " << it->first << " and " << it->second << " already exist!" << std::endl;
				return true;
			}
	}
	return false;
}

neighborhood graph::
get_neighborhood() const
{
	return m_neighborhood;
}

vertices graph::
get_neighbors(const vertex& v)
{
	return m_neighborhood[v];
}

edges graph::
get_edges() const
{
	return m_edges;
}

vertices graph::
get_vertices() const
{
	return m_vertices;
}

void graph::
add_neighborhood(const neighborhood& n)
{
	neighborhood::const_iterator it = n.begin();
	for ( ; it != n.end(); ++it ) {
		vertices::const_iterator v_it = it->second.begin();
		for ( ; v_it != it->second.end(); ++v_it ) {
			add_edge(it->first, *v_it );
		}
	}
}

void graph::
add_vertices(const vertices& vs)
{
	vertices::const_iterator it = vs.begin();
	for( ; it != vs.end(); ++it) {
		vertices::const_iterator v_it = find(m_vertices.begin(), m_vertices.end(), *it);
        	if( v_it != m_vertices.end() ) {
			continue;
		} else {
			m_vertices.push_back(*it);
		}
	}
}

void graph::
add_vertex(const vertex& v) 
{
	if( !is_vertex_in_graph(v) ) {
		m_vertices.push_back(v);
		m_neighborhood.insert( neighborhood::value_type(v, std::vector<int>(0, 0)) );
	}
}

void graph::
add_edges(const edges& ed)
{
	edges::const_iterator it = ed.begin();
	for( ; it != ed.end(); ++it) {
		if(! is_edge_in_graph(*it)) {
			m_edges.push_back(*it);
			add_vertex( it->first );
			add_vertex( it->second );
			vertices::iterator v_it = find(m_neighborhood[it->first].begin(), m_neighborhood[it->first].end(), it->second);
			if ( v_it == m_neighborhood[it->first].end() ) {
				m_neighborhood[it->first].push_back(it->second);
			}
			v_it = find(m_neighborhood[it->second].begin(), m_neighborhood[it->second].end(), it->first);
			if ( v_it == m_neighborhood[it->second].end() ) {
				m_neighborhood[it->second].push_back(it->first);
			}
		}
	}	
}

void graph::
add_edge(const vertex& s, const vertex& d) 
{
    if ( s == d ) {
        std::cout << __FUNCTION__ << ": Error: source and destination are the same." << std::endl;
	}

	if (! is_edge_in_graph(s, d)) {
		m_edges.push_back(edge(s, d));
		add_vertex(s);
		add_vertex(d);
		vertices::iterator it = find(m_neighborhood[s].begin(), m_neighborhood[s].end(), d);
		if ( it == m_neighborhood[s].end() ) {
			m_neighborhood[s].push_back(d);
		}
		it = find(m_neighborhood[d].begin(), m_neighborhood[d].end(), s);
		if ( it == m_neighborhood[d].end() ) {
			m_neighborhood[d].push_back(s);
		}
	}
}

void graph::
add_edge(const edge& e)
{
	if(! is_edge_in_graph(e)) {
		m_edges.push_back(e);
		add_vertex(e.first);
		add_vertex(e.second);
		vertices::iterator it = find(m_neighborhood[e.first].begin(), m_neighborhood[e.first].end(), e.second);
		if ( it == m_neighborhood[e.first].end() ) {
			m_neighborhood[e.first].push_back(e.second);
		}
		it = find(m_neighborhood[e.second].begin(), m_neighborhood[e.second].end(), e.first);
		if ( it == m_neighborhood[e.second].end() ) {
		   m_neighborhood[e.second].push_back(e.first);
		}
	}
}

graph::          
graph(const neighborhood& n)
{
    m_neighborhood = n;
	add_neighborhood(n);
}

graph::        
graph(const graph& g)
{
	m_vertices.clear();
	m_neighborhood.clear();
	m_edges.clear();
	edges::const_iterator eit = g.m_edges.begin();
	for( ; eit != g.m_edges.end(); ++eit) {
		add_edge(*eit);
	}
	vertices::const_iterator vit = g.m_vertices.begin();
	for ( ; vit != g.m_vertices.end(); ++vit ) {
		add_vertex(*vit);
	}
}

graph::
graph() 
{
        
} 

graph::
~graph() 
{
}

graph& graph::
operator =(const graph& g)
{
	m_vertices.clear();
	m_neighborhood.clear();
	m_edges.clear();
	edges::const_iterator eit = g.m_edges.begin();
	for( ; eit != g.m_edges.end(); ++eit) {	
		add_edge(*eit);
	}
	vertices::const_iterator vit = g.m_vertices.begin();
	for ( ; vit != g.m_vertices.end(); ++vit ) {
		add_vertex(*vit);
	}
	
	return *this;
}

///////Helper/////

void graph::
print_neighborhood() const
{
	neighborhood::const_iterator it = m_neighborhood.begin();
	for ( ; it != m_neighborhood.end(); ++it ) {
		std::cout << it->first << "  --> " ;
		vertices::const_iterator v_it = it->second.begin();
		for ( ; v_it != it->second.end(); ++v_it ) {
				std::cout <<", " << *v_it; 
		}
		std::cout << std::endl;
	}
}