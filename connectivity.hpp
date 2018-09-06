//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  connectivity.hpp
//  @brief GraphAlgo::connectivity class
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
//  @brief The Connectivity algorithm tests whether a graph is connected and 
//         makes graph's connected components vector
//.............................................................................
// @brief Two separate disjoint subgraphs. From initial Graph removed vertex(7)
//        and edge(6, 11).
//
//             2 . . . . . . . . . 5                   8 . . . . . . . . . 16
//           .   .                                       .               . .
//         .       .                                       .           .   .
//       .           .                                       .       .     .
//     .               .                                       .   .       .
//   1 . . . . . . . . . 4                                       10        .
//                     .   .                                   .           .
//                   .       .                               .             .
//                 .           .                           .               .
//               .               .                       .                 .
//             3 . . . . . . . . . 6                   9 . . . . . . . . . 15
//           .   .               .                   .                   . 
//         .       .           .                   .                   .   
//       .           .       .                   .                   .     
//     .               .   .                   .                   .       
//  13 . . . . . . . . . 12                 11 . . . . . . . . . 14        
//
//.............................................................................
//  @brief Printing connectivity algorithm output subgraphs as adjacency-list:
//         Graph is not connected
//         +++++++++++++++++++++++
//          1  -->  2,  4
//          2  -->  1,  4,  5
//          3  -->  4,  6, 12, 13
//          4  -->  1,  2,  3,  6
//          5  -->  2
//          6  -->  3,  4, 12
//         12  -->  3,  6, 13
//         13  -->  3, 12
//         +++++++++++++++++++++++
//          8  --> 10, 16
//          9  --> 10, 11, 15
//         10  -->  8,  9, 16
//         11  -->  9, 14
//         14  --> 11, 15
//         15  -->  9, 14, 16
//         16  -->  8, 10, 15
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#ifndef CONNECTIVITY_HPP
#define CONNECTIVITY_HPP

#include <iostream>
#include "graph.hpp"
#include "dfs.hpp"

namespace GraphAlgo
{
	
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
	
}; // end namespace

#endif

