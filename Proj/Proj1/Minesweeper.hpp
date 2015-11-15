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
    Minesweeper(std::string);
    ~Minesweeper() {delete mField;}
    
    
    void init() const;
    bool cont() const;
private:
    std::string name; /// player name
    Grid *mField; /// the minefield
};



#endif /* Minesweeper_hpp */
