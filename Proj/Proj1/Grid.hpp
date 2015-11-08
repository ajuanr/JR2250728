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
    typedef SimpleVector<SimpleVector<short> > ss; // 2d vector
    typedef SimpleVector<short> sv;
    
    Grid(short size=10){this->size=size;}
    void init();
    void setMines(short=20);
    void print() const;
    void prntObscr();
private:
    ss grid;
    short size; // grid will have area size x size
    
    enum Flag {EMPTY=10, MINE=87, CLEAR, LOSER};
};
#endif /* Grid_hpp */
