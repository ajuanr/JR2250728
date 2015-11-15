//
//  main.cpp
//  Project
//
//  Created by Juan Ruiz on 11/7/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

// system libraries
#include <iostream>

// user libraries
#include "Grid.hpp"
#include "Minesweeper.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Enter your name: ";
    string name;
    cin >> name;
    
    Minesweeper *player = new Minesweeper();
    player->init();
    bool cont = true;
    while(cont){
        /// if this result if false, player has lost
        if(!player->cont()) {
            cont = false;
        }
        /// if this result is true, plyaer has won
        if (player->victory()) {
            cont=false;
        }
    }
    if (player->victory()) {
        cout << "You win!!!\n";
    }
    else cout << "You lose\n";
    
    return 0;
}

//    Grid *area = new Grid();
//    area->init();
//    //area->create();
//    //area->setMines();
//    cout << "is: " << area->test(1,5) << endl;
//    //area->print();
//    cout << area->hasWon() << endl;
//    area->prntObscr();
//    std::cout << endl;
//    area->prntClr();
//    delete area;
