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

Minesweeper::Minesweeper(){
    mField = new Grid();
}

void Minesweeper::init() const {
    cout << "Welcome, time to play some Minesweeper!\n";
    mField->init();
}

bool Minesweeper::cont() const{
    cout << "Choose a space to test.\n";
    short row=3, col;
    row=testInput("row");
    col = testInput("column");
    cout << "row: " << row << " column: " << col << endl;

    return mField->test(row, col);
}

/// function testInput ask for an a value to be entered and checks
/// that the input is valid. Repeats until valid input is entered
/// or counter reaches 10 attemps
short Minesweeper::testInput(string s) const{
    string prompt = "Enter the " + s + "\n";
    cout << prompt;
    short n;
    cin >> n;
    /// to prevent to much looping
    short counter=0;

    while(cin.fail() && counter!=10) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << prompt;
        cin >> n;
        ++counter;
    }
    if(counter==10) n = 0;
    return n;
}