//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  biconnectivity.hpp
//  @brief GraphAlgo::biconnectivity class
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
// @brief planar graph with 16 vertices and 24 edges. From initial graph is
//        removed edge(6, 11)
//
//             2 . . . . . . . . . 5                   8 . . . . . . . . . 16
//           .   .                   .                   .               . .
//         .       .                   .                   .           .   .
//       .           .                   .                   .       .     .
//     .               .                   .                   .   .       .
//   1 . . . . . . . . . 4 . . . . . . . . . 7 . . . . . . . . . 10        .
//                     .   .                 .                 .           .
//                   .       .               .               .             .
//                 .           .             .             .               .
//               .               .           .           .                 .
//             3 . . . . . . . . . 6         .         9 . . . . . . . . . 15
//           .   .               .           .       .                   . 
//         .       .           .             .     .                   .   
//       .           .       .               .   .                   .     
//     .               .   .                 . .                   .       
//  13 . . . . . . . . . 12                 11 . . . . . . . . . 14        
//
//.............................................................................
//  @brief Graph is not bicoconnected.
//         cut vertex 4
//         cut vertex 7
//  @brief Printing graph's biconected components as adjacency-list:
//         +++++++++++++++++++++++
//          3  --> 13, 12,  6,  4
//          4  -->  6,  3
//          6  --> 12,  4,  3
//         12  --> 13,  3,  6
//         13  -->  3, 12
//         +++++++++++++++++++++++
//          7  --> 11, 10
//          8  --> 16, 10
//          9  --> 11, 10, 15
//         10  -->  9, 16,  8,  7
//         11  --> 14,  7,  9
//         14  --> 15, 11
//         15  --> 14,  9, 16
//         16  --> 15, 10,  8
//         +++++++++++++++++++++++
//          1  -->  4,  2
//          2  -->  5,  4,  1
//          4  -->  7,  1,  2
//          5  -->  2,  7
//          7  -->  5,  4
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#ifndef BICONNECTIVITY_HPP
#define BICONNECTIVITY_HPP

#include <stack>
#include <set>

#include "graph.hpp"

namespace GraphAlgo
{
	
	typedef std::stack<edge> edge_stack;
	typedef std::set<int> cutvertices;
	typedef std::map<vertex, int> parent;
	typedef std::map<vertex, int> discovery_time;
	typedef std::map<vertex, int> back;

	typedef std::vector<graph> graphs;


	class biconnectivity
	{
	private:
		int time; 
		edge_stack m_edge_stack;
		parent m_parent;
		discovery_time m_discovery_time;
		back m_back;

		graph g_in;
		graphs graphs_out;
		vertices m_vertices;
		cutvertices m_cutvertices;
		neighborhood m_neighborhood;

		void new_bicomponent(const vertex&, const vertex&);
		void biDFS(const vertex&);
		void bicomponents();

	public:
		bool is_biconnected() const;
		void print_cutvertices() const;
		biconnectivity(const graph&);
		~biconnectivity();
		graphs& operator() ();
	};
	
}; // end namespace

#endif

