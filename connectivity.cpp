//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  connectivity.cpp
//  @brief GraphAlgo::connectivity class defination
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
//  @brief The Connectivity algorithm tests whether a graph is connected and 
//         makes graph's connected components vector
//  @brief This algorithm uses DFS algorithm for testing conectivity
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#include "connectivity.hpp"

using namespace GraphAlgo;



void connectivity::
connected_parts( graph& g_in ) 
{
	while( !g_in.get_vertices().empty() )
	{
		initialize();	

		graph g_copy = g_in;
		visit::iterator it = m_visit.begin();
		for ( ; it != m_visit.end(); ++it )
		{
			if ( it->second == false ) {
				g_copy.remove_vertex(it->first);
			}
			if ( it->second == true ) {
				g_in.remove_vertex(it->first);	
			}
		}
		graphs_out.push_back( g_copy );

		connected_parts( g_in );
	}
}


bool connectivity::
is_connected()
{
	initialize();	

	visit::iterator it = m_visit.begin();
	for( ; it != m_visit.end(); ++it )
	{
		if ( it->second == false ) {
			return false;
		}
	}
	return true;
}


void connectivity::
initialize()
{	
	vertex first = g_in.get_vertices().front();
	
	dfs tree(g_in, first);
	
	m_visit.clear();
	m_visit = tree.get_visit();
}


connectivity::
connectivity( const graph& g )
{
	g_in = g;
}


connectivity::
~connectivity()
{

}

graphs& connectivity::
operator() ()
{
	connected_parts(g_in);

	return graphs_out;
}

