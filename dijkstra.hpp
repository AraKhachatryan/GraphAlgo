/******************************************************************************
*  @brief
*  ALGORITHM ShortestPath(G,v):
*      INPUT: A simple undirected weighted graph G with nonnegative edge 
*         weights and a distinguished vertex v of G
*      OUTPUT: A label D[u], for each vertex u of G, such that D[u] is the 
*         length of a shortest path from v to u in G
*      INITIALIZE D[v] ← 0 and D[u] ← +∞ for each vertex u ≠ v.
*      Let a priority queue Q contain all the vertices of G using the 
*         D labels as keys.
*      WHILE Q is not empty do
*          {pull a new vertex u into the cloud}
*          u ← Q.removeMin()
*          FOR EACH vertex z adjacent to u such that z is in Q Do
*              {perform the relaxation procedure on edge (u, z)}
*              IF D[u] + w((u, z)) < D[z] THEN
*                  D[z] ← D[u] + w((u, z))
*                  Change to D[z] the key of vertex z in Q.
*      RETURN the label D[u] of each vertex u
******************************************************************************/

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <map>
#include <set>
#include <list>

#include "graph.hpp"

#include <limits> // for numeric_limits
#define infinity std::numeric_limits< double >::infinity()

typedef std::set< std::pair<double, vertex> > vertex_queue;
typedef std::map<vertex, double> vertex_distance;
typedef std::map<vertex, vertex> vertex_previous;
typedef std::map<edge, double> edge_weight;
typedef std::list<vertex> vertex_path;

//typedef std::queue<int, std::greater<int> > v_queue;

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

public:
	void print_path();
	vertex_path get_shortest_path_to(const vertex&);

	void set_edge_weight(const vertex&, const vertex&, double);
	void set_edge_weight(const edge&, double);
	double get_edge_weight(const vertex&, const vertex&);
	
	void relaxation(const vertex&, const vertex&);
	void initialize(const vertex&);
	void shortest_paths_from(const vertex&);

	dijkstra(const graph&);
	~dijkstra();
};

#endif
