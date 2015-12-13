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
    Edge(Vertex v):a(v), b(a){};
    Edge(Vertex v, Vertex w): a(v), b(w){};
    Vertex& mate(Vertex v){return (v.get()==a.get())?b:a;}
private:
    Vertex a;
    Vertex b;
};

#endif /* Edge_hpp */
