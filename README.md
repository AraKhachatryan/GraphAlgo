# Algorithms library for planar graphs (C++):

Graph represented as adjacency lists. Used STL containers and iterators. Implemented with OOP.
This library for educational purposes and and very simple for understanding.

<img align="left" width="540" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph.jpg">

```C++
Printing graph as adjacency list:
 1  -->  2,  4
 2  -->  1,  4,  5
 3  -->  4,  6, 12, 13
 4  -->  1,  2,  3,  6,  7
 5  -->  2,  7
 6  -->  3,  4, 11, 12
 7  -->  4,  5, 10, 11
 8  --> 10, 16
 9  --> 10, 11, 15
10  -->  7,  8,  9, 16
11  -->  6,  7,  9, 14
12  -->  3,  6, 13
13  -->  3, 12
14  --> 11, 15
15  -->  9, 14, 16
16  -->  8, 10, 15
```


The graph class based on adjacency lists
```C++
typedef int vertex;
typedef std::pair<int, int> edge;
typedef std::vector<int> vertices;
typedef std::vector<edge> edges;
typedef std::map<vertex, vertices> neighborhood;

class graph 
{
private:
	edges m_edges;
	vertices m_vertices;
	neighborhood m_neighborhood;
        
public: //Helper
	void print_neighborhood() const; 

public:
	void remove_vertex(vertex);
	void remove_edge(vertex, vertex);
	
	bool is_vertex_in_graph(const vertex&) const;
	bool is_edge_in_graph(const edge&) const;
	bool is_edge_in_graph(const vertex&, const vertex&) const;
	
	neighborhood get_neighborhood() const;
	vertices get_neighbors(const vertex&);
	edges get_edges() const;
	vertices get_vertices() const;
	
	void add_neighborhood(const neighborhood&);
	void add_vertices(const vertices&);
	void add_vertex(const vertex&);
	void add_edges(const edges&);
	void add_edge(const vertex&, const vertex&);
	void add_edge(const edge&);
	
	graph(const neighborhood&);
	graph(const graph&);
	graph(); 
	~graph();
	graph& operator =(const graph&);
};
```

**Implemented algorithms:**
 - Depth-first search algorithm (making spanning tree of input graph)
 - Connectivity algorithm (determine whether a graph is connected and make graph's connected components vector) 
 - Biconnectivity algorithm (determine whether a graph is biconnected and and make graph's biconnected components vector)
 - Dijkstra's shortest path algorithm of weighted graph
 
 </br>
 
 ## Getting Started
 
 For running and testing the program in Linux download the graph algorithms library source code files. Open in Linux terminal downloaded folder and compile it. To simplify the compilation, I wrote a makefile. Type in terminal make command and program will be compiled. The executable file will be named as folder name. </br>
 
 In main.cpp file shown how to use graph algorithms library. For building graph in main.cpp file created an object of graph class and called on it graph class add_edge() method. You can build a graph with your own data using graph class add_  methods.
 
 **DFS algorithm:** </br>
 The DFS algorithm is implemented in dfs.hpp and dfs.cpp files. In main.cpp file created an object of DFS class with input of above created initial graph and start vertex 1. Then DFS algorithm traversal output is printed on terminal.
 
<img align="right" width="540" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph_DFS.jpg">

```C++
Graphs DFS algorithm output:
 1  -->  2
 2  -->  1,  4
 3  -->  4,  6
 4  -->  2,  3
 5  -->  7
 6  -->  3, 11, 12
 7  --> 11,  5, 10
 8  --> 10, 16
 9  --> 15
10  -->  7,  8
11  -->  6,  7
12  -->  6, 13
13  --> 12
14  --> 15
15  --> 16,  9, 14
16  -->  8, 15
```

 **Connectivity algorithm:** </br>
 The connectivity algorithm is implemented in connectivity.hpp and connectivity.cpp files. The initial is connected. In order to demonstrate connectivity algorithm in main.cpp file from initial graph removed vertex 7 and edge (6, 11) with g.remove_vertex(7) and g.remove_edge(6, 11) methods respectively. Now we have two separate disjoint subgraphs. The connectivity algorithm tests for connectivity condition and print out in terminal disjoint subgraphs of graph.
 
 <img align="right" width="540" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph_Connectivity.jpg">
 
```C++
~~~~~~~~~~connectivity~~~~~~~~~~
Graph is not connected
+++++++++++++++++++++++
 1  -->  2,  4
 2  -->  1,  4,  5
 3  -->  4,  6, 12, 13
 4  -->  1,  2,  3,  6
 5  -->  2
 6  -->  3,  4, 12
12  -->  3,  6, 13
13  -->  3, 12
+++++++++++++++++++++++
 8  --> 10, 16
 9  --> 10, 11, 15
10  -->  8,  9, 16
11  -->  9, 14
14  --> 11, 15
15  -->  9, 14, 16
16  -->  8, 10, 15
```

**Biconectivity algorithm:** </br>
The biconectivity algorithm is implemented in biconnectivity.hpp and biconnectivity.cpp files. The initial graph is strongly connected i.e biconnected. In order to demonstrate biconnectivity algorithm in main.cpp file from initial graph removed the edge (6-11) with method g.remove_edge(6, 11). Then in main.cpp file created an object of biconnectivity class with input of above created initial graph. In The graph vertex 4 and 7 is cutvertices: if if these will be removed we'll receive three separate not connected graphs. The biconnectivity algorithm output is printed on terminal.

<img align="right" width="540" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph_Biconectivity.jpg">

```C++
cut vertex 4
cut vertex 7
Graph is not biconnected
+++++++++++++++++++++++
 3  --> 13, 12,  6,  4
 4  -->  6,  3
 6  --> 12,  4,  3
12  --> 13,  3,  6
13  -->  3, 12
+++++++++++++++++++++++
 7  --> 11, 10
 8  --> 16, 10
 9  --> 11, 10, 15
10  -->  9, 16,  8,  7
11  --> 14,  7,  9
14  --> 15, 11
15  --> 14,  9, 16
16  --> 15, 10,  8
+++++++++++++++++++++++
 1  -->  4,  2
 2  -->  5,  4,  1
 4  -->  7,  1,  2
 5  -->  2,  7
 7  -->  5,  4
```
 
 **Dijkstra's shortest path algorithm:** </br>
 The Dijkstra's shortest path algorithm is implemented in dijkstra.hpp and dijkstra.cpp files. In main.cpp file created an object of Dijkstra class with input of initial graph. Then on Dijkstra type object called set_edge_weight(const vertex&, const vertex&, double) method, where first two arguments are graph edges identifiers and last third argument is edge weight. Start vertex is 1 and end vertex is 14. Algorithm will find shortest path in weighted graph from vertices 1 to 14.
 
 <img align="right" width="540" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph_Weighted.jpg">
 
 ```C++
dijkstra dijk(g);

dijk.set_edge_weight(1, 2, 1);
dijk.set_edge_weight(1, 4, 5);	
dijk.set_edge_weight(2, 4, 3);
dijk.set_edge_weight(2, 5, 2);
dijk.set_edge_weight(3, 4, 4);
...
...
...
dijk.set_edge_weight(11, 14, 1);
dijk.set_edge_weight(12, 13, 2);
dijk.set_edge_weight(14, 15, 1);
dijk.set_edge_weight(15, 16, 2);

dijk.shortest_paths_from(1);
dijk.get_shortest_path_to(14);
```
After execution of Dijkstra's shortest path algorithm the shortest path is printed on terminal.

<img align="right" width="540" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph_Shortest_Path.jpg">

 ```C++
~~~~~~~~~~~~~~Dijkstra~~~~~~~~~~~~~~
Path from 1 to 14 is:
 1 2 5 7 10 8 16 15 14
Hope count: 8
Path cost: 11

Path from 1 to 9 is:
 1 2 5 7 10 9
Hope count: 5
Path cost: 9

Path from 13 to 8 is:
 13 3 4 7 10 8
Hope count: 5
Path cost: 11
```
 
</br>
 
  ## Graph algorithm visualisation on 250 vertices
Dijkstra's algorithm visualisation on 250 vertices:
<p align="left">
  <img src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Dijkstra.jpg">
</p>

DFS algorithm visualisation on 250 vertices:
<p align="left">
  <img src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/dfs.jpg">
</p>
