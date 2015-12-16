//
//  Minesweeper.hpp
//  Project
//
//  Created by Juan on 11/15/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef Minesweeper_hpp
#define Minesweeper_hpp

/// System libraries
#include <string>

/// User libraries
#include "Grid.hpp"

class Minesweeper {
public:
    /// constructors/ destructors
    Minesweeper();
    ~Minesweeper() {delete mField;}
    
    
    void init() const;
    bool cont() const;
    
    bool victory() { return mField->hasWon();}
private:
    Grid *mField; /// the minefield
    
    /// Utility Functions
    short testInput(string) const;
};

#endif /* Minesweeper_hpp */
