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

        g.add_edge(1, 2);
        g.add_edge(2, 3);
        g.add_edge(3, 4);
	g.add_edge(3, 7);
        g.add_edge(4, 7);
        g.add_edge(4, 8);
        g.add_edge(5, 6);
        g.add_edge(5, 9);
	g.add_edge(5, 10);
        g.add_edge(6, 9);
	g.add_edge(7, 10);
	g.add_edge(7, 11);
        g.add_edge(7, 12);
        g.add_edge(8, 12);
        g.add_edge(9, 10);
        g.add_edge(9, 13);
        g.add_edge(9, 14);
	g.add_edge(10, 11);
	g.add_edge(10, 13);
	g.add_edge(11, 12);
        g.add_edge(11, 15);
        g.add_edge(12, 16);
        g.add_edge(13, 14);
        g.add_edge(15, 16);
/*
	g.add_edge(21, 22);
	g.add_edge(21, 25);
	g.add_edge(21, 27);
	g.add_edge(21, 28);
	g.add_edge(22, 28);
	g.add_edge(23, 26);
	g.add_edge(23, 27);
	g.add_edge(23, 29);
	g.add_edge(24, 27);
	g.add_edge(24, 28);
	g.add_edge(26, 29);
*/	

	g.print_neighborhood();

/*
	std::cout << "~~~~~~~~~~~~~~~~~~dfs~~~~~~~~~~~~~~~~~~" << std::endl;
	graph gr;
	dfs d(g,4);
	gr = d();
	gr.print_neighborhood();
*/

/*
	std::cout << "~~~~~~~~~~~~~~~connectivity~~~~~~~~~~~~~~~" << std::endl;
	g.remove_vertex(10);
	g.remove_edge(2, 3);
	g.remove_vertex(9);
	connectivity con(g);
//	if(!con.is_connected()) {std::cout << "Not connected" << std::endl;}
	
	graphs graphs_out;
	graphs_out = con();
	graphs::const_iterator it = graphs_out.begin();
        for( ; it != graphs_out.end(); ++it) {
                std::cout << "+++++++++++++++++++++++" << std::endl;
                it->print_neighborhood();
        }

*/

	
	std::cout << "~~~~~~~~~~~~~~~~~~biDFS~~~~~~~~~~~~~~~~~~" << std::endl;
	g.remove_vertex(8);	
	biconnectivity bi( g );
	graphs graphs_out;
	graphs_out = bi();
        graphs::const_iterator it = graphs_out.begin();
        for( ; it != graphs_out.end(); ++it) {
                std::cout << "+++++++++++++++++++++++" << std::endl;
                it->print_neighborhood();
        }


/*
	std::cout << "~~~~~~~~~~~~~~~~~Dijkstra~~~~~~~~~~~~~~~~~~~" << std::endl;
	
	dijkstra dijk(g);

	dijk.set_edge_weight(1, 2, 2);
	dijk.set_edge_weight(2, 3, 5);
	dijk.set_edge_weight(3, 4, 4);
	dijk.set_edge_weight(3, 7, 2);
	dijk.set_edge_weight(4, 7, 4);
	dijk.set_edge_weight(4, 8, 2);
	dijk.set_edge_weight(5, 6, 7);
	dijk.set_edge_weight(5, 9, 1);
	dijk.set_edge_weight(5, 10, 2);
	dijk.set_edge_weight(6, 9, 6);
	dijk.set_edge_weight(7, 10, 8);
	dijk.set_edge_weight(7, 11, 5);
	dijk.set_edge_weight(7, 12, 2);
	dijk.set_edge_weight(8, 12, 4);
	dijk.set_edge_weight(9, 10, 3);
	dijk.set_edge_weight(9, 13, 2);
	dijk.set_edge_weight(9, 14, 5);
	dijk.set_edge_weight(10, 11, 4);
	dijk.set_edge_weight(10, 13, 3);
	dijk.set_edge_weight(11, 12, 1);
	dijk.set_edge_weight(11, 15, 2);
	dijk.set_edge_weight(12, 16, 4);
	dijk.set_edge_weight(13, 14, 4);
	dijk.set_edge_weight(15, 16, 3);

	dijk.shortest_paths_from(1);
	dijk.get_shortest_path_to(14);
	dijk.print_path();
	dijk.get_shortest_path_to(15);
	dijk.print_path();

	dijk.shortest_paths_from(14);
	dijk.get_shortest_path_to(2);
	dijk.print_path();
*/

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
