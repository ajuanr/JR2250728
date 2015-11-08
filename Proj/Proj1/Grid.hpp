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
    
    Grid(short size=10);
    void init();
    void create();
    void setMines();
    void print() const;
    void prntObscr() const;
    void prntClr() const;
private:
    // Various flags place on grid
    enum Flag {EMPTY=10, MINE=87, CLEAR, LOSER};
    
    // data
    ss grid;
    short size; // grid will have area size x size
    
    // utility functions
    short nAdjacent(short, short, Flag=MINE) const;
    void setFlags();
    bool isClear(short, short) const;
    
};
#endif /* Grid_hpp */
