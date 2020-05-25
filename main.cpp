// A C++ program for Bellman-Ford's single source 
// shortest path algorithm. 
#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>

using namespace std;

std::unordered_map<int, std::string> names_ = {{0, "BTC"},
                                               {1, "USD"},
                                               {2, "ETH"},
                                               {3, "LTC"},
                                               {4, "XRP"},
                                               {5, "LINK"},
                                               {6, "BCH"},
                                               {7, "XLM"}};

enum {
    BTC, USD, ETH, LTC, XRP, LINK, BCH, XLM, n_vertices
};

// a structure to represent a weighted edge in graph
struct Edge {
    int src, dest;
    double weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E) {
    auto *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// A utility function used to print the solution
void printArr(double dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i) {
        printf("%s \t\t %f\n", names_[i].c_str(), dist[i]);
    }
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
void BellmanFord(struct Graph *graph, int src) {
    int V = graph->V;
    int E = graph->E;
    double dist[V];

    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = DBL_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            double weight = graph->edge[j].weight;
            if (dist[u] != DBL_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        double weight = graph->edge[i].weight;
        if (dist[u] != DBL_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply return
        }
    }

    printArr(dist, V);
}

// Driver program to test above functions
int main() {
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph *graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[BTC].src = BTC;
    graph->edge[BTC].dest = USD;
    graph->edge[BTC].weight = -1;

    //enum { BTC, USD, ETH, LTC, XRP, LINK, BCH, XLM, n_vertices };
    // add edge 0-2 (or A-C in above figure)
    graph->edge[USD].src = BTC;
    graph->edge[USD].dest = ETH;
    graph->edge[USD].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[ETH].src = USD;
    graph->edge[ETH].dest = ETH;
    graph->edge[ETH].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[LTC].src = USD;
    graph->edge[LTC].dest = LTC;
    graph->edge[LTC].weight = 2;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[XRP].src = USD;
    graph->edge[XRP].dest = XRP;
    graph->edge[XRP].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[LINK].src = LTC;
    graph->edge[LINK].dest = ETH;
    graph->edge[LINK].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[BCH].src = LTC;
    graph->edge[BCH].dest = USD;
    graph->edge[BCH].weight = USD;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[XLM].src = XRP;
    graph->edge[XLM].dest = LTC;
    graph->edge[XLM].weight = -3;

    BellmanFord(graph, BTC);

    return 0;
} 