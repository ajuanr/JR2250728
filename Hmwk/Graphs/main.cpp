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
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Vertex a("a");
    Vertex b("b");
    Edge e(a, b);
    cout << e.mate(a).get() << endl;
    cout << e.mate(b).get() << endl;
    
    
    return 0;
}
