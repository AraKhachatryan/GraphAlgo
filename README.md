# Algorithms library for planar graphs (C++):

Graph represented as adjacency lists. Used STL containers and iterators. Implemented with OOP.
This library for educational purposes and and very simple for understanting.

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
 - Biconnectivity algorithm (determine whether a graph is biconnected and and make graph's connected components vector)
 - Dijkstra's shortest path algorithm of weighted graph
 
 ## Grtting Started
 
 For running and testing the program in Linux download the graph algorithms library source code files. Open in Linux terminal downloaded folder and compile it. To simplify the compilation, I wrote a makefile. Type in terminal make command and program will be compiled. The executable file will be named as folder name. </br>
 
 For building graph in main.cpp file called graph class add_edge() method. You can build a graph with your own data using graph class add_ methods.
 
 The DFS algorithm is implemented in dfs.hpp and dfs.cpp files. In main.cpp file created an object of DFS class with input of above created initial graph and start vertex 1. Then DFS algorithm traversal output is printed on terminal.
 
<img align="left" width="540" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph_DFS.jpg">

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

The biconectivity algorithm is implemented in biconnectivity.hpp and biconnectivity.cpp files. Initial graph is strongly conected i.e biconected. In order to demonstrate biconectivity algorithm in main.cpp file from initial graph removed the edge 6-11 with method g.remove_edge(6, 11). Then in main.cpp file created an object of biconectivity class with input of above created initial graph. In The graph vertice 7 is cutvertice: if it will be removed we'll receive two separate not conected graphs. The biconectivity algorithm output is printed on teminal.

<img align="left" width="540" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph_Biconectivity.jpg">
 
**Dijkstra's algorithm visualisation on 250 vertices:**
<p align="left">
  <img src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Dijkstra.jpg">
</p>
