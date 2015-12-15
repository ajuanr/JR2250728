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
    typedef std::map<Vertex, std::set<Vertex> > graphContainer;
    
    Graph():numVertices(0), numEdges(0) {}
    Graph(const Edge&);
    Graph(const Vertex&);
    void addEdge(const Edge&);
    void addEdge(const Vertex&,const Vertex&, int weight);
    void addVertex(const Vertex&);
    
    void print() const;
private:
    graphContainer graph;
    int numVertices;
    int numEdges;
};


#endif /* Graph_hpp */
