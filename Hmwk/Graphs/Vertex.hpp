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
    Vertex():data(0){};
    Vertex(int val):data(val){};
    
    void set(int val){data = val;}
    int get() const {return data;}
    
private:
    int data;
};


#endif /* Vertex_hpp */
