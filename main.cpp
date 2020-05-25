#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char *argv[]) {

/*
    graph dij(8);
    dij.add_edge(0,2,4,0);
    dij.add_edge(0,5,7,0);
    dij.add_edge(2,3,3,0);
    dij.add_edge(2,5,2,0);
    dij.add_edge(5,6,8,0);
    dij.add_edge(2,6,9,0);
    dij.add_edge(3,4,3,0);
    dij.add_edge(3,6,7,0);
    dij.add_edge(6,4,2,0);
    dij.add_edge(6,7,3,0);
    dij.add_edge(4,7,7,0);
    dij.add_edge(7,1,3,0);
    // dij.add_edge(4,1,9,0);
    dij.Dijkstra(0,1);
    dij.add_edge(4,1,4,0);
*/
    // dij.GreedyBFS(0, 2,1);
    /*
       cout << "------------- Graph test 5 (Floyd Warshall) -------------\n";
       graph floyd(5);
       floyd.add_edge(0,3,3,1);
       floyd.add_edge(0,2,6,1);
       floyd.add_edge(1,0,3,1);
       floyd.add_edge(2,3,2,1);
       floyd.add_edge(3,2,1,1);
       floyd.add_edge(3,1,1,1);
       floyd.add_edge(4,1,4,1);
       floyd.add_edge(4,3,2,1);
       floyd.print();
       auto pair = floyd.floydWarshall();
       pair.first.print();
       pair.second.print();
       // https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg
       graph dij(9);
       dij.add_edge(0,1,4,0);
       dij.add_edge(0,7,8,0);
       dij.add_edge(1,7,11,0);
       dij.add_edge(1,2,8,0);
       dij.add_edge(7,8,7,0);
       dij.add_edge(7,6,1,0);
       dij.add_edge(8,2,2,0);
       dij.add_edge(8,6,6,0);
       dij.add_edge(2,5,4,0);
       dij.add_edge(6,5,2,0);
       dij.add_edge(2,3,7,0);
       dij.add_edge(3,5,14,0);
       dij.add_edge(5,4,10,0);
       dij.add_edge(3,4,9,0);
       // https://www.youtube.com/watch?v=obWXjtg0L64
       graph bellman(6);
       bellman.add_edge("F", "E", 8, 1);
       bellman.add_edge("F", "A", 10, 1);
       bellman.add_edge("A", "C", 2, 1);
       bellman.add_edge("B", "A", 1, 1);
       bellman.add_edge("C", "B", -2, 1);
       bellman.add_edge("D", "C", -1, 1);
       bellman.add_edge("D", "A", -4, 1);
       bellman.add_edge("E", "D", 1, 1);
       bellman.add_edge("A", "C", 2, 1);
       bellman.print();
       bellman.bellmanFord("F");
       graph bellman(5);
       bellman.add_edge("A", "B", -1, 1);
       bellman.add_edge("A", "C", 4, 1);
       bellman.add_edge("B", "C", 3, 1);
       bellman.add_edge("B", "D", 2, 1);
       bellman.add_edge("B", "E", 2, 1);
       bellman.add_edge("A", "C", 4, 1);
       bellman.add_edge("D", "B", 1, 1);
       bellman.add_edge("A", "C", 4, 1);
       bellman.add_edge("D", "C", 5, 1);
       bellman.add_edge("E", "D", 3, 1);
       bellman.print();
       bellman.bellmanFord("F", 1);
   */

    graph Graph;
    Graph.add_node(1, 0, 0);
    Graph.add_node(2, 1, 2);
    Graph.add_node(3, 1, 0);
    Graph.add_node(4, 1, -2);
    Graph.add_node(5, 3, 2);
    Graph.add_node(6, 3, 0);
    Graph.add_node(7, 3, -2);
    Graph.add_node(8, 5, -2);
    Graph.add_node(9, 5, 0);

    Graph.add_edge(1, 2, 5, true);
    Graph.add_edge(1, 3, 25, true);
    Graph.add_edge(2, 5, 11, true);
    Graph.add_edge(2, 6, 33, true);
    Graph.add_edge(3, 4, 17, true);
    Graph.add_edge(3, 6, 38, true);
    Graph.add_edge(4, 7, 12, true);
    Graph.add_edge(5, 6, 21, true);
    Graph.add_edge(5, 9, 1, true);
    Graph.add_edge(6, 4, 4, true);
    Graph.add_edge(6, 7, 3, true);
    Graph.add_edge(7, 8, 50, true);
    Graph.add_edge(8, 6, 41, true);
    Graph.add_edge(9, 6, 2, true);
    Graph.add_edge(9, 8, 14, true);


    cout << "\nbellmanFord:\n";
    Graph.bellmanFord(5, true);


    return EXIT_SUCCESS;
}