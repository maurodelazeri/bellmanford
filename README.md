# Bellman–Ford Algorithm

```c++
#include <iostream>
#include "directed_graph.h"

using namespace std;

int main() {

    auto graph = new Graph();
    graph->add_node("A");
    graph->add_node("B");
    graph->add_node("C");
    graph->add_node("D");
    graph->add_node("E");

    graph->add_edge("A", "B", -1);
    graph->add_edge("A", "C", 4);
    graph->add_edge("B", "C", 3);
    graph->add_edge("B", "D", 2);
    graph->add_edge("A", "E", 2);
    graph->add_edge("D", "C", 5);
    graph->add_edge("D", "B", 1);
    graph->add_edge("E", "D", -3);

    std::vector<std::vector<std::string>> vec;
    cout << graph->bellman_ford("A",vec) << endl;
    
    for (auto const &x : vec) {
       cout << x[0] << " - " << x[1] << endl;
    }

    graph->print();

    delete graph;

    return 0;
}

```

![](9tX9a5R.png)

```
0
A - 0
B - -1
C - 2
D - -1
E - 2
A: 
	weight: -1 to: B
	weight: 4 to: C
	weight: 2 to: E
B: 
	weight: 3 to: C
	weight: 2 to: D
C: 
D: 
	weight: 5 to: C
	weight: 1 to: B
E: 
	weight: -3 to: D


```


