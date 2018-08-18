# Algorithms library for planar graphs (C++):

Graph represented as adjacency lists. Used STL containers and iterators. Implemented with OOP.
This library for educational purposes and and very simple for understanting.

<img  width="100%" height="100%" src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Graph.jpg">

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
 - Dijkstra's shortest path algorithm of weighted graph
 - Biconnectivity algorithm (determine whether a graph is biconnected and and make graph's connected components vector)
 
 ## Grtting Started
 For running and testing the program in Linux download the graph algorithms library source code files. Open in Linux terminal downloaded folder and compile it. To simplify the compilation, I wrote a makefile. Type in terminal make command and program will be compiled. The executable file will be named as folder name.
 
**Dijkstra's algorithm visualisation on 250 vertices:**
<p align="left">
  <img src="https://github.com/AraKhachatryan/Graph-Algorithms/blob/master/img/Dijkstra.jpg">
</p>
