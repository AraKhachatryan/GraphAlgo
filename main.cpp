//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  main
//  @brief demonstration of GraphAlgo library 
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************


#include <iostream>
#include <thread>
#include <chrono>


// for terminal text color
#include "namespace_terminal.hpp"

// our GraphAlgo: Algorithms library for planar graphs
#include "GraphAlgo.hpp"

// for drawing graphs in terminal for visualisation
void draw_graph( const std::vector<std::string> &graph_data );
// graph data for drawing from graph_data.cpp
extern const std::vector<std::string> graph_data;
extern const std::vector<std::string> graph_data_dfs;
extern const std::vector<std::string> graph_data_connectivity;
extern const std::vector<std::string> graph_data_biconnectivity;
extern const std::vector<std::string> graph_data_dijkstra;



int main()
{
	// Printing a headline in terminal, used namespace termianl for text colors
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~ "
			  << terminal::TEXT_BOLD << terminal::TEXTCOLOR_BLUE
			  << "GraphAlgo: Algorithms library for planar graphs."
			  << terminal::RESET_ALL
			  << "~~~~~~~~~~~~~~~" << std::endl;
	
	// Initialize an empty graph object
	GraphAlgo::graph g;

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
	
	
	// Drawing a graph on terminal for visualisation
	draw_graph( graph_data );
	
	
	std::cout << "Printing graph as adjacency-list:" << std::endl;
	g.print_neighborhood();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));  // sleep
	
	
	
	
	std::cout << std::endl << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DFS Algorithm ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << std::endl << std::endl;
	
	// making dfs object and starting the algorithm from vertex 1 in graph g
	GraphAlgo::dfs depth_first(g, 1);
	
	GraphAlgo::graph g_out_dfs;
	g_out_dfs = depth_first();
	
	
	std::cout << "Executing DFS algorithm on initial graph with start vertex 1" << std::endl;
	// Drawing a graph on terminal for DFS Algorithm visualisation
	draw_graph( graph_data_dfs );	
	
	
	std::cout << "Print DFS algorithm output as adjacency-list:" << std::endl;
	g_out_dfs.print_neighborhood();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));  // sleep
	
	
	
	
	std::cout << std::endl << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ Connectivity Algorithm ~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << std::endl << std::endl;
	
	GraphAlgo::graph g_con = g;   // copy intitial graph		
	g_con.remove_vertex(7);       // remove vertex for disconecting a graph
	g_con.remove_edge(6, 11);     // remove edge for disconecting a graph
	
	std::cout << "Vertex 7 and edge (6, 11) removed from initial graph.";
	std::cout << std::endl;
//	g_con.print_neighborhood();
	
	
	// Drawing a graph on terminal for Connectivity visualisation
	draw_graph( graph_data_connectivity );	
	
	
	// making connectivity object and starting the algorithm
	GraphAlgo::connectivity con(g_con);
	
	if( !con.is_connected() )
	{
		std::cout << "Graph is not connected." << std::endl;
	} else {
		std::cout << "Graph not connected." << std::endl;
	}
	
	GraphAlgo::graphs con_out;
	con_out = con();
	
	std::cout << "Printing disconected graph's conected components:";
	std::cout << std::endl;
	
	GraphAlgo::graphs::const_iterator c_it = con_out.begin();
	for( ; c_it != con_out.end(); ++c_it) 
	{	
		std::cout << "+++++++++++++++++++++++" << std::endl;
		c_it->print_neighborhood();
	}
	
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));  // sleep
	
	
	
	
	std::cout << std::endl << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~ BiConnectivity Algorithm ~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << std::endl << std::endl;
	 
	GraphAlgo::graph g_bicon = g;  // copy intitial graph
	g_bicon.remove_edge(6, 11);    // for making graph not biconected
	
	std::cout << "From initial graph is removed edge(6, 11)." << std::endl;
//	g_bicon.print_neighborhood();
	
	
	// Drawing a graph on terminal for BiConnectivity visualisation
	draw_graph( graph_data_biconnectivity );	
	
	
	// making biconnectivity object and starting the algorithm
	GraphAlgo::biconnectivity bicon( g_bicon );
	
	if ( !bicon.is_biconnected() ) 
	{
		std::cout << "Graph is not bicoconnected." << std::endl;
		// Print cutvertices
		bicon.print_cutvertices();
	} else {
		std::cout << "Graph is bicoconnected." << std::endl;
	}
	
	GraphAlgo::graphs bicon_out;
	bicon_out = bicon();
	
	std::cout << "Printing graph's biconected components:" << std::endl;
	GraphAlgo::graphs::const_iterator b_it = bicon_out.begin();
	for( ; b_it != bicon_out.end(); ++b_it) 
	{
		std::cout << "+++++++++++++++++++++++" << std::endl;
		b_it->print_neighborhood();
	}
	
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));  // sleep
	
	
	
	
	std::cout << std::endl << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ Dijkstra's Algorithm ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << std::endl << std::endl;
	
	// making dijkstra object from initial graph g
	GraphAlgo::dijkstra dijk(g);
	
	// 
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
	
	
	// Drawing a graph on terminal for Dijkstra's Algorithm visualisation
	draw_graph( graph_data_dijkstra);	
	

	dijk.shortest_paths_from(1);
	dijk.get_shortest_path_to(14);
	dijk.print_path();
	std::cout << std::endl;
	
	// another shortest path: from 1 to 9
	dijk.get_shortest_path_to(9);
	dijk.print_path();
	std::cout << std::endl;

	// another shortest path: from 13 to 8
	dijk.shortest_paths_from(13);
	dijk.get_shortest_path_to(8);
	dijk.print_path();


	std::cout << std::endl << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << std::endl << std::endl;
	
	
	return 0;
}




void draw_graph( const std::vector<std::string> &graph_data )
{
	// Printing a graph via graph_data
	std::cout << std::endl;
	std::cout << terminal::TEXT_BOLD << terminal::TEXTCOLOR_BLUE;
	
	for ( auto &line : graph_data )
	{
		std::cout << "   " << line << std::endl;
	}
	
	std::cout << terminal::RESET_ALL;
	std::cout << std::endl;
	std::cout << "................................................................................" << std::endl;	
	
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));   // sleep
}

