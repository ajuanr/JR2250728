//
//  Vertex.hpp
//  Graphs
//
//  Created by Juan Ruiz on 12/10/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <string>

class Vertex {
public:
    Vertex():id(0), visited(false){};
    Vertex(std::string val):id(val), visited(false){};
    std::string get() const{return id;}
    void visit() {visited = true;}
    void unvisit() {visited = false;}
    operator std::string() {return id;}
    
private:
    std::string id;
    bool visited;
};


#endif /* Vertex_hpp */
