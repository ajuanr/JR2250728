//
//  Grid.cpp
//  Project
//
//  Created by Juan Ruiz on 11/7/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

// system libraries
#include <iostream>

// User Libraries
#include "Grid.hpp"

void Grid::init() {
    for(int i = 0; i != 10; i++) {
        grid.push_back(SimpleVector<int>());
        for(int j = 0; j != 10; j++) {
            grid[i].push_back(i);
        }
    }
}

void Grid::print() const {
    typedef ss::const_iterator cit;
    typedef SimpleVector<int>::const_iterator it;
    for(cit i = grid.begin(); i != grid.end(); ++i)
    {
        for(it j = i->begin(); j != i->end();
            ++j) {
            std::cout << *j << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;
}