//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  dijkstra.hpp
//  @brief GraphAlgo::dijkstra class
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
// @brief planar wighted graph with 16 vertices and 25 edges
//
//             2 + + + + 2 + + + + 5                   8 + + + + 1 + + + + 16
//           +   .                   +                   +               . +
//         1       3                   1                   1           3   +
//       +           .                   +                   +       .     +
//     +               .                   +                   +   .       +
//   1 . . . . 5 . . . . 4 . . . . 3 . . . . 7 + + + + 2 + + + + 10        2
//                     .   .                 .                 .           +
//                   4       5               .               .             +
//                 .           .             .             .               +
//               .               .           .           .                 +
//             3 . . . . 2 . . . . 6         9         9 . . . . 2 . . . . 15
//           .   .               .   .       .       .                   + 
//         1       3           1       5     .     4                   1   
//       .           .       .           .   .   .                   +     
//     .               .   .               . . .                   +       
//  13 . . . . 2 . . . . 12                 11 . . . . 1 . . . . 14        
//
//.............................................................................
//  @brief Shortest path from 1 to 14 is:
//         1 2 5 7 10 8 16 15 14
//         Hope count: 8
//         Path cost: 11
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <limits> // for numeric_limits

#include <map>
#include <set>
#include <list>

#include "graph.hpp"



namespace GraphAlgo
{
	const double infinity  = std::numeric_limits< double >::infinity();

	typedef std::set< std::pair<double, vertex> > vertex_queue;
	typedef std::map<vertex, double> vertex_distance;
	typedef std::map<vertex, vertex> vertex_previous;
	typedef std::map<edge, double> edge_weight;
	typedef std::list<vertex> vertex_path;

//	typedef std::queue<int, std::greater<int> > v_queue;

	class dijkstra
	{
	private:
		graph g_in;
		vertices m_vertices;
		edges m_edges;
		neighborhood m_neighborhood;

		vertex_path v_path;

		vertex_previous v_previous;
		vertex_distance v_distance;
		vertex_queue v_queue;
		edge_weight e_weight;

		void relaxation( const vertex&, const vertex& );
		void initialize( const vertex& );

	public:
		void print_path();

		vertex_path get_shortest_path_to( const vertex& );

		void set_edge_weight( const vertex&, const vertex&, double );
		void set_edge_weight( const edge&, double );

		double get_edge_weight( const vertex&, const vertex& );

		void shortest_paths_from( const vertex& );

		dijkstra( const graph& );
		~dijkstra();
	};
	
	
}; // end namespace

#endif

