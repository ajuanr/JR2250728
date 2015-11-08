//
//  Grid.cpp
//  Project
//
//  Created by Juan Ruiz on 11/7/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

// system libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

// User Libraries
#include "Grid.hpp"

void Grid::init() {
    for(int i = 0; i != 10; i++) {
        grid.push_back(SimpleVector<short>());
        for(int j = 0; j != 10; j++) {
            grid[i].push_back(EMPTY);
        }
    }
}

void Grid::print() const {
    typedef ss::const_iterator cit;
    typedef SimpleVector<short>::const_iterator it;
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

void Grid::setMines(short n) {
    srand(static_cast<unsigned int>(time(0)));
    /// holds how many mines will be used
    short mines = n;
    
    /// keep looping through minefield until all mines are set
    typedef sv::iterator iv;
    typedef ss::iterator is;
    while (mines) {
        for ( is i = grid.begin(); i != grid.end(); ++i) {
            for (iv j = i->begin(); j != i->end(); ++j) {
                /// place mines if result of rand()%15 == 0
                if ((rand() % 100 + 1) % 100 == 0){
                    ///only place mines if mines are still available
                    /// and current is empty
                    if (mines && *j == EMPTY) {
                        /// set the mine
                        *j = MINE;
                        --mines;
                    }
                }
            }
        }
    }
}

/// Function prints the minefield with spaces hidden
void Grid::prntObscr() {
    /// Print the column index
    for (short i = 0; i != mf->cols; ++i){
        /// Pad initial output of column indicator
        if (i==0)
            cout << "  ";
        cout << setw(3) << i;
    }
    cout << endl;
    for (short row = 0; row != mf->rows; ++row){
        for (short col = 0; col != mf->cols; ++col){
            if(col == 0 && row < 10) cout << row << "  ";
            if (col == 0 && row >= 10) cout << row << " ";
            /// KEEP EMPTY spaces and MINEs hidden
            if (mf->data[row][col] == MineField::EMPTY ||
                mf->data[row][col] == MineField::MINE)
                cout << setw(3) << right  << "* ";
            /// print out the CLEARed area
            else if (mf->data[row][col] == MineField::CLEAR)
                cout << setw(2)<< 0 << " ";
            /// Print out the actual value of the square
            else
                cout << setw(2)<< mf->data[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}