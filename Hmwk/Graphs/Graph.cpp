//
//  Graph.cpp
//  Graphs
//
//  Created by Juan Ruiz on 12/13/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>

#include "Graph.hpp"

using namespace std;

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
    graph[e.Dest()].insert(e.Src());
}

void Graph::addEdge(const Vertex &a, const Vertex &b, int weight) {
    Edge *temp = new Edge(a, b, weight);
    addEdge(*temp);
    
    delete temp;
}

void Graph::print() const {
    for (graphContainer::const_iterator it = graph.begin(); it != graph.end();
     ++it) {
        cout << it->first.get();
        for (set<Vertex>::const_iterator sit = it->second.begin();
             sit != it->second.end(); ++sit) {
            cout << " - "<<  "> " << sit->get();
        }
        cout << endl;
    }
    
    cout << endl;
}

//*******************************
//**** operator overloading *****
//*******************************
bool operator< (const Vertex &lhs, const Vertex &rhs ) {
    if (lhs.get() < rhs.get()) return true;
    if (rhs.get() < lhs.get()) return false;
    return lhs.get() < rhs.get();
}

bool operator< (const Edge &lhs, const Edge &rhs) {
    if (lhs.Src() < rhs.Src()) return true;
    if (rhs.Src() < lhs.Src()) return false;
    return lhs.Dest() < rhs.Dest();
}