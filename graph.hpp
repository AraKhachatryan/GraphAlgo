//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  graph.hpp
//  @brief GraphAlgo::graph class
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
//  @brief Graph abstract data type based on adjacency-lists data structure
//  @param neighborhood is adjacency-list data structure which is declared as 
//         typedef std::map<vertex, vertices> neighborhood;
//  @param neighborhood type is std::map<int, std::vector<int>>
//.............................................................................
// @brief planar graph with 16 vertices and 25 edges
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
//           .   .               .   .       .       .                   . 
//         .       .           .       .     .     .                   .   
//       .           .       .           .   .   .                   .     
//     .               .   .               . . .                   .       
//  13 . . . . . . . . . 12                 11 . . . . . . . . . 14        
//
//.............................................................................
//  @brief Printing same graph as adjacency-list:
//          1  -->  2,  4
//          2  -->  1,  4,  5
//          3  -->  4,  6, 12, 13
//          4  -->  1,  2,  3,  6,  7
//          5  -->  2,  7
//          6  -->  3,  4, 11, 12
//          7  -->  4,  5, 10, 11
//          8  --> 10, 16
//          9  --> 10, 11, 15
//         10  -->  7,  8,  9, 16
//         11  -->  6,  7,  9, 14
//         12  -->  3,  6, 13
//         13  -->  3, 12
//         14  --> 11, 15
//         15  -->  9, 14, 16
//         16  -->  8, 10, 15
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <map>
#include <utility> //for std::pair< , >



namespace GraphAlgo
{
	
	typedef int vertex;
	typedef std::vector<int> vertices;
	typedef std::pair<int, int> edge;
	typedef std::vector<edge> edges;
	typedef std::map<vertex, vertices> neighborhood;

	class graph 
	{
	private:
		edges m_edges;
		vertices m_vertices;
		neighborhood m_neighborhood;

	public: 
		// prints in terminal graph's neighborhood (in other words, adjacency-list)
		void print_neighborhood() const; 

	public:
		void remove_vertex( vertex );
		void remove_edge( vertex, vertex);

		bool is_vertex_in_graph( const vertex& ) const;
		bool is_edge_in_graph( const edge& ) const;
		bool is_edge_in_graph( const vertex&, const vertex& ) const;
		
		neighborhood get_neighborhood() const;
		vertices get_neighbors( const vertex& );
		edges get_edges() const;
		vertices get_vertices() const;
		
		void add_neighborhood( const neighborhood& );
		void add_vertices( const vertices& );
		void add_vertex( const vertex& );
		void add_edges( const edges& );
		void add_edge( const vertex&, const vertex& );
		void add_edge( const edge& );
		
		graph( const neighborhood& );
		graph( const graph& );
		graph(); 
		~graph();
		graph& operator=( const graph& );
	};
		
}; // end namespace

#endif

