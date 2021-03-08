// https://www.boost.org/doc/libs/1_75_0/libs/graph/doc/quick_tour.html

#include <iostream>     // for std::cout
#include <utility>      // for std::pair
#include <algorithm>    // for std::for_each

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

int main() {
    // create a typedef for the graph type
    typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;

    // Make convenient labels for the vertices
    enum { A, B, C, D, E };
    const int num_vertices = 5;
    const char* name = "ABCDE";

    // writing out the edges in the graph
    typedef std::pair<int, int> Edge;
    Edge edge_array[] = {
        Edge(A, B), Edge(A, D), Edge(C,A), Edge(D,C),
        Edge(C, E), Edge(B, D), Edge(D,E)
    };
    const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);

    // Declare a graph object
    Graph g(num_vertices);

    // add the edges to the graph object
    for(int i=0; i<num_edges; ++i) {
        add_edge(edge_array[i].first, edge_array[i].second, g);
    }

    // Accessing the Edge Set
    // get the property map for vertex indices
    typedef property_map<Graph, vertex_index_t>::type IndexMap;
    IndexMap index = get(vertex_index, g);
    // accessing edge set
    graph_traits<Graph>::edge_iterator ei, ei_end;
    for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
        std::cout << "(" << index[source(*ei, g)] << "," << index[target(*ei, g)] << ") ";
    std::cout << std::endl;
    
    return 0;
}
