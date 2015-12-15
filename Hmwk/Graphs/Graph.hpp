//
//  Graph.hpp
//  Graphs
//
//  Created by Juan Ruiz on 12/13/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <map>
#include <set>

#include "Edge.hpp"

class Graph {
public:
    Graph():numVertices(0), numEdges(0) {}
    Graph(const Edge&);
    Graph(const Vertex&);
    void addEdge(const Edge&);
    void addVertex(const Vertex&);
private:
    std::map<Vertex, std::set<Vertex> > graph;
    int numVertices;
    int numEdges;
};

//*******************************
//**** operator overloading *****
//*******************************
bool operator< (const Vertex &lhs, const Vertex &rhs ) {
    if (lhs < rhs) return true;
    if (rhs < lhs) return false;
    return lhs < rhs;
}

bool operator< (const Edge &lhs, const Edge &rhs) {
    if (lhs.Src() < rhs.Src()) return true;
    if (rhs.Src() < lhs.Src()) return false;
    return lhs.Dest() < rhs.Dest();
}


#endif /* Graph_hpp */
