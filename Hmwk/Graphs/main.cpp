//
//  main.cpp
//  Graphs
//
//  Created by Juan Ruiz on 12/10/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

// system Libraries
#include <iostream>

/// User libraries
#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Vertex a("a");
    Vertex b("b");
    Vertex c("c");
    Vertex d("d");
    Vertex e("e");
    Edge edge(a, b, 12);
    
    Graph *graph = new Graph();
    graph->addVertex(a);
    graph->addVertex(b);
    graph->addEdge(edge);
    
    graph->addEdge(a, c, 10);
    graph->addEdge(b, c, 15);
    graph->addEdge(d, c, 10);
    graph->addEdge(d, e, 20);
    graph->addEdge(d, e, 12);
    
    graph->print();
    
    delete graph;
    
    return 0;
}
