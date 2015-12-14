//
//  Edge.hpp
//  Graphs
//
//  Created by Juan Ruiz on 12/10/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include "Vertex.hpp"

class Edge {
public:
    Edge(Vertex v):src(v), dest(v){};
    Edge(Vertex v, Vertex w): src(v), dest(w){};
    Vertex& mate(Vertex v){return (v.get()==src.get())?dest:src;}
private:
    Vertex src;
    Vertex dest;
    int weight;
};

#endif /* Edge_hpp */
