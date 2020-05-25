#ifndef EDGE_H
#define EDGE_H

#include "node.h"

template<typename G>
class Edge {
public:
    typedef typename G::E E; // bag E from Graph
    typedef typename G::node node;
    // between which nodes is
    node *nodes[2];

private:
    E peso; //E es tipo int
    bool dir;

public:
    Edge(node *Vi, node *Vf, E peso, bool dir) : peso(peso), dir(dir) {
        nodes[0] = Vi;
        nodes[1] = Vf;
    }

    int get_weight() { return peso; }

    bool get_dir() { return dir; }

    bool operator==(Edge<G> cmp) {
        return nodes[0] == cmp.nodes[0] &&
               nodes[1] == cmp.nodes[1];
    }

    //Compare by weight
    //If they are equal, compare by the value of nodes
    bool operator>(Edge<G> cmp) const {
        return cmp.peso == peso ? nodes[1] > cmp.nodes[1] : peso > cmp.peso;
    }

    bool operator<(Edge<G> cmp) const {
        return cmp.peso == peso ? nodes[1] < cmp.nodes[1] : peso < cmp.peso;
    }

    ~Edge() {
        nodes[0] = nodes[1] = nullptr;
    }
};

#endif
