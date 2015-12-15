//
//  Graph.hpp
//  Graphs
//
//  Created by Juan Ruiz on 12/13/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include "Edge.cpp"
#include <list>

class Graph {
public:
    Graph():numVertices(0), numEdges(0) {}
private:
    std::list<Edge> edges;
    int numVertices;
    int numEdges;
};

#endif /* Graph_hpp */
