#ifndef NODE_H
#define NODE_H

template<typename G>
class Node {
public:
    //get Graph types
    typedef typename G::N N;
    typedef typename G::E E;
    typedef typename G::edge edge;
    typedef typename G::EdgeSeq EdgeSeq;
private:
    N data; //N is integer type

public:
    double x = 0;
    double y = 0;
    EdgeSeq edges;
    bool thereis = false;

    explicit Node(N nombre) : data(nombre) {};

    Node(N nombre, double _x, double _y) : data(nombre), x(_x), y(_y) {};

    int gradoEntrada = 0;
    int gradoSalida = 0;

    // 0 source (input)
    // 1 sunk (exit)
    // 2 has no type
    int get_tipo() {
        return (!gradoEntrada == !gradoSalida) ? 2 : !gradoEntrada;
    }

    // Access methods
    N get_data() { return data; }

    ~Node() {
        while (!edges.empty()) {
            delete edges.back();
            edges.pop_back();
        }
    }

};

#endif