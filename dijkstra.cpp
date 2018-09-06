//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  dijkstra.cpp
//  @brief GraphAlgo::dijkstra class defination
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
//  @brief  dijkstra's algorithm pseudocode
//
//  ALGORITHM ShortestPath(G,v):
//      INPUT: A simple undirected weighted graph G with nonnegative edge 
//         weights and a distinguished vertex v of G
//      OUTPUT: A label D[u], for each vertex u of G, such that D[u] is the 
//         length of a shortest path from v to u in G
//      INITIALIZE D[v] ← 0 and D[u] ← +∞ for each vertex u ≠ v.
//      Let a priority queue Q contain all the vertices of G using the 
//         D labels as keys.
//      WHILE Q is not empty do
//          {pull a new vertex u into the cloud}
//          u ← Q.removeMin()
//          FOR EACH vertex z adjacent to u such that z is in Q Do
//              {perform the relaxation procedure on edge (u, z)}
//              IF D[u] + w((u, z)) < D[z] THEN
//                  D[z] ← D[u] + w((u, z))
//                  Change to D[z] the key of vertex z in Q.
//      RETURN the label D[u] of each vertex u
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#include "dijkstra.hpp"
#include <iostream>

using namespace GraphAlgo;



void dijkstra::
print_path()
{
	vertex s = v_path.front();
	vertex d = v_path.back();
	std::cout << "Shortest path from " << s << " to " << d << " is:" << std::endl;

	vertex_path::const_iterator it = v_path.begin();
	for ( ; it != v_path.end(); ++it ) 
	{
		if ( it == v_path.begin() || it == v_path.end() ) 
		{
			std::cout << *it; 
		} else {
			std::cout << " -> " << *it;	
		} 
	}
	std::cout << std::endl;
	
/*	
	vertex_path::const_iterator it2 = v_path.begin();
	for( ; it2 != v_path.end(); ++it2 ) 
	{
		std::cout << " " << v_distance[*it2];
	}
	std::cout << std::endl;
*/
	
	std::cout << "Hope count: " << v_path.size() - 1 << std::endl;
	std::cout << "Path cost: " << v_distance[d] << std::endl;
}


vertex_path dijkstra::
get_shortest_path_to( const vertex& d )
{
	v_path.clear();
	v_path.push_front(d);

	vertex v = d;
	
	vertex_previous::const_iterator it_prev;
	while ( (it_prev = v_previous.find(v)) != v_previous.end() ) 
	{
		v = it_prev->second;
		v_path.push_front(v);
	}

	return v_path;
}


void dijkstra::
set_edge_weight( const vertex& s, const vertex& d, double w )
{
	if ( e_weight.find(edge(s,d)) != e_weight.end() ) {
		e_weight[edge(s,d)] = w;
	} else if ( e_weight.find( edge(d,s)) != e_weight.end() ) {
		e_weight[edge(d,s)] = w;
	} else {
		e_weight.insert( edge_weight::value_type(edge(s, d), w) );
	}
}


void dijkstra::
set_edge_weight( const edge& e, double w )
{
	if ( e_weight.find(e) != e_weight.end() ) {
		e_weight[e] = w;
	} else if ( e_weight.find( edge(e.second, e.first)) != e_weight.end() ) {
		e_weight[edge(e.second, e.first)] = w;
	} else {
		e_weight.insert( edge_weight::value_type(e, w) );
	}
}


double dijkstra::
get_edge_weight( const vertex& s, const vertex& d )
{
	if ( e_weight.find(edge(s,d)) != e_weight.end() ) {
		return e_weight[edge(s,d)];
	} else if( e_weight.find(edge(d,s)) != e_weight.end() ) {
		return e_weight[edge(d,s)];
	} else {
		return infinity;
	}
}


void dijkstra::
relaxation( const vertex& s, const vertex& d )
{	
	if ( v_distance[s] + get_edge_weight(s, d) < v_distance[d] ) 
	{
		v_queue.erase( std::make_pair( v_distance[d], d) );
		v_distance[d] = v_distance[s] + get_edge_weight(s, d);
		v_queue.insert( std::make_pair( v_distance[d], d) );

		v_previous[d] = s;
	}
}


void dijkstra::
initialize( const vertex& s )
{
	v_distance.clear();
	v_queue.clear();
	v_previous.clear();
	
	vertices::const_iterator it = m_vertices.begin();
	for ( ; it != m_vertices.end(); ++it ) 
	{
		if( *it != s ) {
			v_distance.insert( vertex_distance::value_type(*it, infinity) );
			v_queue.insert( std::make_pair(infinity, *it) );
		} else {
			v_distance.insert( vertex_distance::value_type(s, 0) );
			v_queue.insert( std::make_pair(0, s) );
		}
	}
	
	edges::const_iterator e_it = m_edges.begin();
	for( ; e_it != m_edges.end(); ++e_it) 
	{
		e_weight.insert( edge_weight::value_type(*e_it, 0) );
	}
}


void dijkstra::
shortest_paths_from( const vertex& s )
{
	initialize(s);
	
	while( !v_queue.empty() ) 
	{
		vertex u = v_queue.begin()->second;
		v_queue.erase(v_queue.begin());		

		vertices::const_iterator it = m_neighborhood[u].begin();
		for ( ; it != m_neighborhood[u].end(); ++it ) 
		{
			relaxation(u, *it);
		}
	}	

}


dijkstra::
dijkstra( const graph& g )
{
	g_in = g;

	m_vertices = g_in.get_vertices();
	m_edges = g_in.get_edges();
	m_neighborhood = g_in.get_neighborhood();

}


dijkstra::
~dijkstra()
{

}

