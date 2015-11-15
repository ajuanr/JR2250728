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
    bool test(short, short);
    bool hasWon() const;
    
private:
    /*********************************************
     *********** Enumerations ****************
     ********************************************/
    enum Flag {EMPTY=10, MINE, CLEAR, LOSER};
    
    /*********************************************
     *********** Member Variables ****************
     ********************************************/
    ss grid;
    short size; // grid will have area size x size
    
    /*********************************************
     *********** Utility Functions ****************
     ********************************************/
    short nAdjacent(short, short, Flag=MINE) const;
    void setFlags();
    bool isClear(short, short) const;
    void showZeros(short, short);
    void setPerim();
    
};
#endif /* Grid_hpp */
