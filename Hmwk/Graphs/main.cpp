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

void problem6();

int main(int argc, const char * argv[]) {
    
    problem6();
    
    return 0;
}

void problem6() {
    Vertex sfo("SFO");
    Vertex bos("BOS");
    Vertex ord("ORD");
    Vertex jfk("JFK");
    Vertex dfw("DFW");
    Vertex mia("MIA");
    Vertex lax("LAX");
    
    Graph *air = new Graph();
    air->addEdge(sfo, bos, 2704);
    air->addEdge(sfo, ord, 1846);
    air->addEdge(ord, bos, 867);
    air->addEdge(ord, jfk, 740);
    air->addEdge(jfk, bos, 187);
    air->addEdge(sfo, dfw, 1464);
    
    air->print();
    
    delete air;
}
