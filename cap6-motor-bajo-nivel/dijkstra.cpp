#include <boost/config.hpp>
#include <iostream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;


int main() {

    // definición de estructuras (tipos) de datos que serán utilizadas
    typedef adjacency_list<listS, vecS, directedS, no_property, property<edge_weight_t, int>> graph_t;

    typedef graph_traits<graph_t>::vertex_descriptor vertex_descriptor;

    typedef graph_traits<graph_t>::edge_descriptor edge_descriptor;

    typedef std::pair<int, int> Edge;


    // parámetros básicos del grafo. Etiquetas textuales asociadas a los vértices, aristas o arcos y sus pesos
    const int num_nodes = 5;
    enum nodes {A, B, C, D, E};
    char name[]= "ABCDE";

    Edge edge_array[] = {
        Edge(A,C), Edge(B, A), Edge(B, D), Edge(C, D), Edge(D, B),
        Edge(D,C), Edge(D, E), Edge(E, A), Edge(E, B), Edge(E, C)
    };

    int weights[] = {2, 7, 4, 2, 12, 4, 3, 1, 2, 3};
    int num_arcs = sizeof(edge_array) / sizeof(Edge);


    // instanciación del grafo
    graph_t g(edge_array, edge_array + num_arcs, weights, num_nodes);
    property_map<graph_t, edge_weight_t>::type weightmap = get(edge_weight, g);


    std::vector<vertex_descriptor> p(num_vertices(g));
    std::vector<int> d(num_vertices(g));
    vertex_descriptor s = vertex(A, g); // Caminos desde A

    dijkstra_shortest_paths(g, s, predecessor_map(&p[0]).distance_map(&d[0]));

    // print_graph
    //std::cout << "Grafo" << std::endl;


    std::cout << "Distancias y nodos padre:" << std::endl;
    graph_traits <graph_t>::vertex_iterator vi, vend;

    for(boost::tie(vi, vend) = vertices(g); vi!=vend; ++vi) {
        std::cout << "Distancia(" <<name[*vi] << ") = " << d[*vi] << ", ";
        std::cout << "Padre(" << name[*vi] << ") = " << name[p[*vi]] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
