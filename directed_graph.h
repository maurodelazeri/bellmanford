#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>
#include <utility>
#include <vector>
#include <string>

class Graph {
public:
    Graph();

    Graph(std::string &);

    ~Graph();

    // static void Init(v8::Handle<v8::Object> target);

    void print();

    void trim();

    void add_node(const std::string &name);

    void add_edge(const std::string &, const std::string &, double);

    void update_edge(const std::string &, const std::string &, double);

    bool search(const std::string &name);

    bool bellman_ford(const std::string &name, std::vector<std::vector<std::string>> &path);

private:
    /* Structs */
    struct GEdge;

    struct GNode {
        std::string name;
        std::vector<GEdge> edges;
        int key;

        GNode(std::string name, int k) : name(std::move(name)), key(k) {}
    };

    struct GEdge {
        double weight;
        GNode *node; // node that the edge is pointed towards

        GEdge(double weight, GNode *&n) : weight(weight), node(n) {}
    };

    /* Variables */
    GNode *source;
    std::vector<GNode> nodes;

    /* Functions */
    static void add_edge(GNode *&origin, GNode *&destination, double weight);

    bool bellman_ford(GNode *&origin, std::vector<std::vector<std::string> > &);

    GNode *get_node(const std::string &name) {
        for (auto &node : nodes) {
            if (name == node.name) {
                return &node;
            }
        }
        // this should be fixed to an empty node
        return &nodes.at(0);
    }
};

#endif