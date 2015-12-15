//
//  Vertex.hpp
//  Graphs
//
//  Created by Juan Ruiz on 12/10/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp


class Vertex {
public:
    Vertex():id(0), visited(false){};
    Vertex(int val):id(val), visited(false){};
    int get() {return id;}
    void visit() {visited = true;}
    void unvisit() {visited = false;}
    operator int () {return id;}
    
private:
    int id;
    bool visited;
};

//bool operator<(const Vertex &a, const Vertex &b) {
//    return a<b;
//}


#endif /* Vertex_hpp */
