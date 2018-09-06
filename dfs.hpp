//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  dfs.hpp
//  @brief GraphAlgo::dfs class
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
//  @brief DFS algorithm pseudocode:
//
//         Algorithm DFS(G, v)
//           INPUT: graph G and a start vertex v of G
//           OUTPUT: labeling of the edges of G
//                   in the connected component of v
//                   as discovery edges and back edges
//           setLabel(v, VISITED)
//           for all e  G.incidentEdges(v)
//               if getLabel(e) = UNEXPLORED
//                   w ← opposite(v,e)
//                   if getLabel(w) = UNEXPLORED
//                       setLabel(e, DISCOVERY)
//                       DFS(G, w)
//                   else
//                       setLabel(e, BACK)
//.............................................................................
// @brief planar graph with 16 vertices and 25 edges
//
//             2 . . . . . . . . . 5                   8 + + + + + + + + + 16
//           +   +                   +                   +               . +
//         +       +                   +                   +           .   +
//       +           +                   +                   +       .     +
//     +               +                   +                   +   .       +
//   1 . . . . . . . . . 4 . . . . . . . . . 7 + + + + + + + + + 10        +
//                     +   .                 +                 .           +
//                   +       .               +               .             +
//                 +           .             +             .               +
//               +               .           +           .                 +
//             3 + + + + + + + + + 6         +         9 + + + + + + + + + 15
//           .   .               +   +       +       .                   + 
//         .       .           +       +     +     .                   +   
//       .           .       +           +   +   .                   +     
//     .               .   +               + + .                   +       
//  13 + + + + + + + + + 12                 11 . . . . . . . . . 14        
//
//.............................................................................
//  @brief Printing DFS algorithm output as adjacency-list:
//         Start vertex is 1.
//          1  -->  2
//          2  -->  1,  4
//          3  -->  4,  6
//          4  -->  2,  3
//          5  -->  7
//          6  -->  3, 11, 12
//          7  --> 11,  5, 10
//          8  --> 10, 16
//          9  --> 15
//         10  -->  7,  8
//         11  -->  6,  7
//         12  -->  6, 13
//         13  --> 12
//         14  --> 15
//         15  --> 16,  9, 14
//         16  -->  8, 15
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#ifndef DFS_HPP
#define DFS_HPP

#include <map>
#include "graph.hpp"



namespace GraphAlgo
{
	
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
	
}; // end namespace
	
#endif

