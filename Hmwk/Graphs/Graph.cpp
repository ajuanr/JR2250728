//
//  Graph.cpp
//  Graphs
//
//  Created by Juan Ruiz on 12/13/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(Vertex &v):numVertices(1), numEdges(0) {
    addVertex(v);
}

Graph::Graph(Edge &e):numVertices(2), numEdges(1) {
    addEdge(e);
}

void Graph::addVertex(Vertex &v) {
    // index the vertex to add it to the container
    graph[v];
}

void Graph::addEdge(Edge &e) {
    graph[e.Src()].insert(e.Dest());
}