#include "directed_graph.h"
#include <sstream>

using namespace std;

Graph::Graph() : source(nullptr) {}

Graph::Graph(string &name) {
    source = new GNode(name, nodes.size());
    nodes.push_back(*source);
}

Graph::~Graph() {
    for (auto & node : nodes) {
        node.edges.clear();
    }
    nodes.clear();
}

void Graph::add_node(const string &name) {
    if (!search(name)) {
        auto *temp = new GNode(name, nodes.size());
        nodes.push_back(*temp);
    }
}

void Graph::add_edge(const std::string &begin, const std::string &end, double weight) {
    if (search(begin)) {
        GNode *origin = get_node(begin);
        GNode *dest;

        if (search(end)) {
            dest = get_node(end);
            add_edge(origin, dest, weight);
        } else {
            cout << "Error: no node \"" << end << "\" exists \n";
        }
    } else {
        cout << "Error: no node \"" << begin << "\" exists \n";
    }
}

void Graph::update_edge(const std::string &begin, const std::string &end, double weight) {
    if (search(begin)) {
        GNode *origin = get_node(begin);
        GNode *dest;

        if (search(end)) {
            dest = get_node(end);
            for (auto & edge : origin->edges) {
                if (edge.node->name == dest->name) {
                    edge.weight = weight;
                }
            }
        } else {
            cout << "Error: no node \"" << end << "\" exists \n";
        }
    } else {
        cout << "Error: no node \"" << begin << "\" exists \n";
    }
}

void Graph::print() {
    for (auto & node : nodes) {
        cout << node.name << ": \n";
        for (auto & edge : node.edges) {
            cout << "\t" << "weight: " << edge.weight
                 << " to: " << edge.node->name << "\n";
        }
    }
}

void Graph::trim() {
    // remove all bad edges from nodes
    for (unsigned long int i = 0;
         i < nodes.size(); ++i) { // this needs to be done probably fewer times, try and prove this
        for (auto & node : nodes) {
            for (unsigned long int x = 0; x < node.edges.size(); ++x) {
                if (node.edges.at(x).node->edges.size() < 2) {
                    node.edges.erase(node.edges.begin() + x);
                }
            }
        }
    }


    // remove all nodes with only one edge
    for (unsigned long int i = 0; i < nodes.size(); ++i) {
        if (nodes.at(i).edges.size() < 2) {
            nodes.erase(nodes.begin() + i);
            if (i < 2) {
                i = 0;
            } else {
                i -= 2;
            }
        }
    }

    // reset all of the key values
    for (unsigned long int j = 0; j < nodes.size(); ++j) {
        nodes.at(j).key = j;
    }

}

bool Graph::search(const std::string &name) {
    for (auto &node : nodes) {
        if (name == node.name) {
            return true;
        }
    }
    return false;
}

bool Graph::bellman_ford(const std::string &name, std::vector<std::vector<std::string>> &path) {
    for (auto &node : nodes) {
        if (name == node.name) {
            GNode *temp = get_node(name);
            return bellman_ford(temp, path);
        }
    }
    return false;
}

void Graph::add_edge(GNode *&origin, GNode *&destination, double weight) {
    auto *temp = new GEdge(weight, destination);
    origin->edges.push_back(*temp);
}

bool Graph::bellman_ford(GNode *&origin, std::vector<std::vector<std::string> > &path) {
    vector<double> distances, parents;
    const double infinity = 99999999;

    // Initilize
    for (auto &node : nodes) {
        if (node.name == origin->name) {
            distances.push_back(0);
        } else {
            distances.push_back(infinity);
        }

        parents.push_back(0.0);
    }

    // Relaxe Edges
    for (unsigned long int v = 0;
         v < nodes.size() - 1; ++v) { // do the main loop v - 1 times, or v times to find negative weights
        bool changed = false;

        for (auto &node : nodes) { // these two loops - for every edge in the graph
            for (unsigned long int m = 0; m < node.edges.size(); ++m) {
                GEdge *temp = &node.edges.at(m);
                GNode *tempNode = &node;
                // If distances[u] + w < distances[v]
                if (distances.at(tempNode->key) + temp->weight < distances.at(temp->node->key) &&
                    distances.at(tempNode->key) != infinity) {
                    changed = true;
                    distances.at(temp->node->key) = temp->weight + distances.at(tempNode->key);
                    parents.at(temp->node->key) = tempNode->key;
                }
            }
        }
        if (!changed) {
            break;
        } else {
            changed = false;
        }
    }

    bool negative_weight = false;
    // Check for negative weight cycles
    for (auto &node : nodes) { // these two loops - for every edge in the graph
        for (unsigned long int m = 0; m < node.edges.size(); ++m) {
            GEdge *temp = &node.edges.at(m);
            GNode *tempNode = &node;
            // If distances[u] + w < distances[v]
            if (distances.at(tempNode->key) + temp->weight < distances.at(temp->node->key) &&
                distances.at(tempNode->key) != infinity) {
                negative_weight = true;
            }
        }
    }

    if (!negative_weight) {

        stringstream weight;
        vector<std::string> key_value;

        for (unsigned long int i = 0; i < nodes.size(); ++i) {
            key_value.push_back(nodes.at(i).name);
            // convery doulbe to string
            weight << distances.at(i);
            key_value.push_back(weight.str());
            path.push_back(key_value);

            key_value.clear();
            weight.clear();
            weight.str(std::string());
        }
    }

    return negative_weight;

}




