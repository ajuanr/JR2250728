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
    typedef ss::const_iterator css;
    typedef sv::const_iterator csv;
    for (css row = grid->begin(); row != grid->end(); ++row){
        for (csv col = row->begin(); col != row->end(); ++col) {
            ///
            if ( *col == LOSER)
                cout << "T  ";
            else if (*col == MINE)
                cout << "x  ";
            else if (!isClear(mf, row, col))
                cout << nAdjacent(mf, row, col) << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
    cout << endl;
}

/// Function returns how  many 'flag' elements surround a given square
short nAdjacent(short row, short col, short FLAG) const {
    short nAd=0;              /// the number of adjacent mines
    
    /// not on first or last row or first or last column
    /// most of the searches take place in this area
    if ( row > 0 && col > 0 && row < mf->rows-1 && col < mf->cols-1) {
        /// search the 3x3 grid surrounding a cell
        for (short i = row-1; i <= row+1; ++i) {
            for (short j = col-1; j <= col+1; ++j)
                if (mf->data[i][j] == FLAG)
                    ++nAd;
        }
    }
    /// on the first row, not on first or last column
    else if ( row == 0 && col > 0 && col < mf->cols - 1) {
        for (short i = row; i <= row+1; ++i) {
            for (short j = col-1; j <= col+1; ++j)
                if (mf->data[i][j] == MineField::MINE)
                    ++nAd;
        }
    }
    /// on the last row, not on first or last column
    else if ( row == mf->rows-1 && col > 0 && col < mf->cols - 1) {
        for (short i = row-1; i <= row; ++i) {
            for (short j = col-1; j <= col+1; ++j)
                if (mf->data[i][j] == MineField::MINE)
                    ++nAd;
        }
    }
    /// on the first column, not on first or last row
    /// search to the right
    else if ( col == 0 && row > 0 && row < mf->rows - 1) {
        for (short i = row-1; i <= row+1; ++i) {
            for (short j = col; j <= col+1; ++j)
                if (mf->data[i][j] == MineField::MINE)
                    ++nAd;
        }
    }
    /// on the last column, not on first or last row
    /// search to the left
    else if ( col == mf->cols-1 && row > 0 && row < mf->rows - 1) {
        for (short i = row-1; i <= row+1; ++i) {
            for (short j = col-1; j <= col; ++j)
                if (mf->data[i][j] == MineField::MINE)
                    ++nAd;
        }
    }
    /// top left corner
    else if (row == 0 && col == 0) {
        if (mf->data[row][col+1] == MineField::MINE) ++nAd;
        if (mf->data[row+1][col] == MineField::MINE) ++nAd;
        if (mf->data[row+1][col+1] == MineField::MINE) ++nAd;
    }
    /// top right corner
    else if (row == 0 && col == mf->cols-1) {
        if (mf->data[row][col-1] == MineField::MINE) ++nAd;
        if (mf->data[row+1][col] == MineField::MINE) ++nAd;
        if (mf->data[row+1][col-1] == MineField::MINE) ++nAd;
    }
    /// bottom left corner
    else if (row == mf->rows-1 && col == 0) {
        if (mf->data[row-1][col] == MineField::MINE) ++nAd;
        if (mf->data[row-1][col+1] == MineField::MINE) ++nAd;
        if (mf->data[row][col+1] == MineField::MINE) ++nAd;
    }
    /// bottom right corner
    else if (row == mf->rows-1 && col == mf->cols-1) {
        if (mf->data[row-1][col-1] == MineField::MINE) ++nAd;
        if (mf->data[row-1][col] == MineField::MINE) ++nAd;
        if (mf->data[row][col-1] == MineField::MINE) ++nAd;
    }
    /// return number of mines from appropriate if statement
    return nAd;
}
