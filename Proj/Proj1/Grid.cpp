//
//  Grid.cpp
//  Project
//
//  Created by Juan Ruiz on 11/7/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

// system libraries
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

// User Libraries
#include "Grid.hpp"

Grid::Grid(short size):size(size) {
    // want to avoid negative size
    if (size < 2) {
        size = 10;
    }
    //init();
}

void Grid::init() {
    create();
    setMines();
    prntObscr();
}

void Grid::create() {
    for(int i = 0; i != 10; i++) {
        grid.push_back(SimpleVector<short>());
        for(int j = 0; j != 10; j++) {
            grid[i].push_back(EMPTY);
        }
    }
}

void Grid::print() const {
    typedef ss::const_iterator cit;
    typedef sv::const_iterator it;
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

void Grid::setMines() {
    srand(static_cast<unsigned int>(time(0)));
    /// holds how many mines will be used
    /// 20 percent of grid is composed of mines
    cout << "Size is : " << size << endl;
    short mines = size - (size*2/10);
    cout << "Number of mines: " << mines << endl;
    (mines<1)?mines=1: mines=mines;
    cout << "New Number of mines: " << mines << endl;
    
    /// keep looping through minefield until all mines are set
    typedef sv::iterator iv;
    typedef ss::iterator is;
    while (mines) {
        for ( is i = grid.begin(); i != grid.end(); ++i) {
            for (iv j = i->begin(); j != i->end(); ++j) {
                /// place mines if result of rand()%10 == 0
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
void Grid::prntObscr() const{
    
    /// Print the column index
    for (int i = 0; i != size; ++i){
        /// Pad initial output of column indicator
        if (i==0)
            cout << "  ";
        cout << std::setw(3) << i;
    }
    cout << endl;
    for (short row = 0; row != size; ++row){
        for (short col = 0; col != size; ++col){
            if(col == 0 && row < size) cout << row << "  ";
            if (col == 0 && row >= size) cout << row << " ";
            /// KEEP EMPTY spaces and MINEs hidden
            if (grid[row][col] == EMPTY ||
                grid[row][col] == MINE)
                cout << setw(3) << right  << "* ";
            /// print out the CLEARed area
            else if (grid[row][col] == CLEAR)
                cout << setw(2)<< 0 << " ";
            /// Print out the actual value of the square
            else
                cout << setw(2)<< grid[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/// Functions prints the minefield with all the squares revealed.
/// used mostly after player loses
void Grid::prntClr() const{
    for (short row = 0; row != size; ++row){
        for (short col = 0; col != size; ++col) {
            ///
            if ( grid[row][col] == LOSER)
                cout << "T  ";
            else if( grid[row][col] == MINE)
                cout << "x  ";
            else if (!isClear(row, col))
                cout << nAdjacent(row, col) << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
    cout << endl;
}

/// Function returns how  many 'flag' elements surround a given square
short Grid::nAdjacent(short row, short col, Flag FLAG) const {
    short nAd=0;              /// the number of adjacent mines
    
    /// not on first or last row or first or last column
    /// most of the searches take place in this area
    if ( row > 0 && col > 0 && row < size-1 && col < size-1) {
        /// search the 3x3 grid surrounding a cell
        for (short i = row-1; i <= row+1; ++i) {
            for (short j = col-1; j <= col+1; ++j)
                if (grid[i][j] == FLAG)
                    ++nAd;
        }
    }
    /// on the first row, not on first or last column
    else if ( row == 0 && col > 0 && col < size - 1) {
        for (short i = row; i <= row+1; ++i) {
            for (short j = col-1; j <= col+1; ++j)
                if (grid[i][j] == FLAG)
                    ++nAd;
        }
    }
    /// on the last row, not on first or last column
    else if ( row == size-1 && col > 0 && col < size - 1) {
        for (short i = row-1; i <= row; ++i) {
            for (short j = col-1; j <= col+1; ++j)
                if (grid[i][j] == FLAG)
                    ++nAd;
        }
    }
    /// on the first column, not on first or last row
    /// search to the right
    else if ( col == 0 && row > 0 && row < size - 1) {
        for (short i = row-1; i <= row+1; ++i) {
            for (short j = col; j <= col+1; ++j)
                if (grid[i][j] == FLAG)
                    ++nAd;
        }
    }
    /// on the last column, not on first or last row
    /// search to the left
    else if ( col == size-1 && row > 0 && row < size - 1) {
        for (short i = row-1; i <= row+1; ++i) {
            for (short j = col-1; j <= col; ++j)
                if (grid[i][j] == FLAG)
                    ++nAd;
        }
    }
    /// top left corner
    else if (row == 0 && col == 0) {
        if (grid[row][col+1] == FLAG) ++nAd;
        if (grid[row+1][col] == FLAG) ++nAd;
        if (grid[row+1][col+1] == FLAG) ++nAd;
    }
    /// top right corner
    else if (row == 0 && col == size-1) {
        if (grid[row][col-1] == FLAG) ++nAd;
        if (grid[row+1][col] == FLAG) ++nAd;
        if (grid[row+1][col-1] == FLAG) ++nAd;
    }
    /// bottom left corner
    else if (row == size-1 && col == 0) {
        if (grid[row-1][col] == FLAG) ++nAd;
        if (grid[row-1][col+1] == FLAG) ++nAd;
        if (grid[row][col+1] == FLAG) ++nAd;
    }
    /// bottom right corner
    else if (row == size-1 && col == size-1) {
        if (grid[row-1][col-1] == FLAG) ++nAd;
        if (grid[row-1][col] == FLAG) ++nAd;
        if (grid[row][col-1] == FLAG) ++nAd;
    }
    /// return number of mines from appropriate if statement
    return nAd;
}

bool Grid::isClear(short row, short col) const{
    if (nAdjacent(row, col))
        return false;            /// there was at least one mine adjacent
    return true;                 /// area was clear
}
