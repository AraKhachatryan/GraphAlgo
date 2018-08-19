#include <iostream>
#include "graph.hpp"
#include "dfs.hpp"
#include "connectivity.hpp"
#include "biconnectivity.hpp"
#include "dijkstra.hpp"

int main()
{
	std::cout << "~~~~~~~~~~~~~~~~~START~~~~~~~~~~~~~~~~" << std::endl;
	graph g;

	// Build a graph via adding edges
	g.add_edge(1, 2);
	g.add_edge(1, 4);	
	g.add_edge(2, 4);
	g.add_edge(2, 5);
	g.add_edge(3, 4);
	g.add_edge(3, 6);
	g.add_edge(3, 12);
	g.add_edge(3, 13);
	g.add_edge(4, 6);
	g.add_edge(4, 7);
	g.add_edge(5, 7);
	g.add_edge(6, 11);
	g.add_edge(6, 12);
	g.add_edge(7, 10);
	g.add_edge(7, 11);
	g.add_edge(8, 10);
	g.add_edge(8, 16);
	g.add_edge(9, 10);
	g.add_edge(9, 11);
	g.add_edge(9, 15);
	g.add_edge(10, 16);
	g.add_edge(11, 14);
	g.add_edge(12, 13);
	g.add_edge(14, 15);
	g.add_edge(15, 16);	
	
	std::cout << "Printing graph as adjacency list:" << std::endl;
	g.print_neighborhood();
	
/*
	std::cout << "~~~~~~~~~~~~~~~~~~dfs~~~~~~~~~~~~~~~~~~" << std::endl;
	graph graph_out_dfs;
	dfs depth_first(g,1);
	graph_out_dfs = depth_first();
	graph_out_dfs.print_neighborhood();
*/

	
/*
	std::cout << "~~~~~~~~~~~~~~connectivity~~~~~~~~~~~~~~" << std::endl;
	g.remove_vertex(7);
	g.remove_edge(6, 11);
	connectivity con(g);
	
	if( !con.is_connected() )
	{
		std::cout << "Graph is not connected" << std::endl;
	} else {
		std::cout << "Graph not connected" << std::endl;
	}
	
	graphs graphs_out;
	graphs_out = con();
	
	graphs::const_iterator it = graphs_out.begin();
	for( ; it != graphs_out.end(); ++it) {	
		std::cout << "+++++++++++++++++++++++" << std::endl;
		it->print_neighborhood();
	}
*/


/*
	std::cout << "~~~~~~~~~~~~~~biconnectivity~~~~~~~~~~~~~~" << std::endl;
	g.remove_edge(6, 11);
	biconnectivity bicon( g );
	
	if ( !bicon.is_biconnected() ) {
		std::cout << "Graph is not bicoconnected" << std::endl;
	} else {
		std::cout << "Graph is bicoconnected" << std::endl;
	}
	
	graphs graphs_out;
	graphs_out = bicon();
	
	graphs::const_iterator it = graphs_out.begin();
	for( ; it != graphs_out.end(); ++it) {
		std::cout << "+++++++++++++++++++++++" << std::endl;
		it->print_neighborhood();
	}
*/


	std::cout << "~~~~~~~~~~~~~~~~Dijkstra~~~~~~~~~~~~~~~~~~" << std::endl;
	
	dijkstra dijk(g);

	dijk.set_edge_weight(1, 2, 1);
	dijk.set_edge_weight(1, 4, 5);	
	dijk.set_edge_weight(2, 4, 3);
	dijk.set_edge_weight(2, 5, 2);
	dijk.set_edge_weight(3, 4, 4);
	dijk.set_edge_weight(3, 6, 2);
	dijk.set_edge_weight(3, 12, 3);
	dijk.set_edge_weight(3, 13, 1);
	dijk.set_edge_weight(4, 6, 6);
	dijk.set_edge_weight(4, 7, 3);
	dijk.set_edge_weight(5, 7, 1);
	dijk.set_edge_weight(6, 11, 5);
	dijk.set_edge_weight(6, 12, 1);
	dijk.set_edge_weight(7, 10, 2);
	dijk.set_edge_weight(7, 11, 9);
	dijk.set_edge_weight(8, 10, 1);
	dijk.set_edge_weight(8, 16, 1);
	dijk.set_edge_weight(9, 10, 3);
	dijk.set_edge_weight(9, 11, 4);
	dijk.set_edge_weight(9, 15, 2);
	dijk.set_edge_weight(10, 16, 3);
	dijk.set_edge_weight(11, 14, 1);
	dijk.set_edge_weight(12, 13, 2);
	dijk.set_edge_weight(14, 15, 1);
	dijk.set_edge_weight(15, 16, 2);

	dijk.shortest_paths_from(1);
	dijk.get_shortest_path_to(14);
	dijk.print_path();
	std::cout << std::endl;
	
	dijk.get_shortest_path_to(9);
	dijk.print_path();
	std::cout << std::endl;

	dijk.shortest_paths_from(13);
	dijk.get_shortest_path_to(8);
	dijk.print_path();


/*
	std::cout << "~~~~~~~~~~~~add_vertex,remove...~~~~~~~" << std::endl;
	g.add_vertex(99);
	g.remove_edge(10, 7);
	g.remove_edge(10, 11);
	g.remove_vertex(10);
	g.remove_vertex(2);
	g.print_neighborhood();
*/

	std::cout << "~~~~~~~~~~~~~~~~~END~~~~~~~~~~~~~~~~~~~" << std::endl;
	return 0;
}
