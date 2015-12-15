//
//  Graph.cpp
//  Graphs
//
//  Created by Juan Ruiz on 12/13/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(const Vertex &v):numVertices(1), numEdges(0) {
    addVertex(v);
}

Graph::Graph(const Edge &e):numVertices(2), numEdges(1) {
    addEdge(e);
}

void Graph::addVertex(const Vertex &v) {
    // index the vertex to add it to the container
    graph[v];
}

void Graph::addEdge(const Edge &e) {
    graph[e.Src()].insert(e.Dest());
}

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