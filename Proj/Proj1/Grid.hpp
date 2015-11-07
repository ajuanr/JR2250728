//
//  Grid.hpp
//  Project
//
//  Created by Juan Ruiz on 11/7/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include "SimpleVector.h"

class Grid{
public:
    typedef SimpleVector<SimpleVector<int> > ss; // 2d vector
    
    Grid(int=10);
    void init();
    void setMines();
    void print() const;
private:
    ss grid;
    short size; // grid will have area size x size
    
    enum Flag {EMPTY=10, MINE, CLEAR, LOSER};
};
#endif /* Grid_hpp */
