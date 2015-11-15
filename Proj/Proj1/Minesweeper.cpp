//
//  Minesweeper.cpp
//  Project
//
//  Created by Juan on 11/15/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include "Minesweeper.hpp"
#include <iostream>

using namespace std;

Minesweeper::Minesweeper(std::string name): name(name) {
    mField = new Grid();
}

void Minesweeper::init() const {
    cout << "Welcome " << name << ", time to play some Minesweeper!\n";
    mField->init();
}

bool Minesweeper::cont() const{
    cout << "Choose a space to test.\n";
    int row, col;
    cout << "Enter the row: ";
    cin >> row;
    cout << "Enter the column: ";
    cin >> col;
    return mField->test(row, col);
}