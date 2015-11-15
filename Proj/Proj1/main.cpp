//
//  main.cpp
//  Project
//
//  Created by Juan Ruiz on 11/7/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

/// system libraries
#include <fstream>
#include <iostream>
#include <map>
#include <string>

/// user libraries
#include "LnkdLst.hpp"
#include "Minesweeper.hpp"

using namespace std;


int playOnce();
void printData(map<string, LnkdLst<int> >&, ostream&); // print previous game histories

int main(int argc, const char * argv[]) {
    cout << "Enter your name: ";
    string name;
    cin >> name;
    
    int score = playOnce();
    
    map<string, LnkdLst<int> > pData; /// holds players data
    pData[name].append(score);
    
    printData(pData, cout);
    
    ofstream outFile("PlayerScores.txt");

    if (outFile.is_open()) {
    printData(pData, outFile);
    outFile.close();
    }
    else
        cout << "File failed to open";
    
    return 0;
}

int playOnce() {
    Minesweeper *player = new Minesweeper();
    player->init();
    bool cont = true;
    int score =0;
    unsigned int beg = time(0);
    while(cont){
        /// if this result if false, player has lost
        if(!player->cont()) {
            cont = false;
        }
        /// each turn without losing gives the player 10 points
        else score+=10;
        /// if this result is true, plyaer has won
        if (player->victory()) {
            cont=false;
        }
    }
    unsigned int end = time(0);
    cout << "Total time is: " << end - beg << endl;
    if (player->victory()) {
        cout << "You win!!!\n";
    }
    else cout << "You lose\n";
    
    return score;
}

void printData(map<string, LnkdLst<int> >& m, ostream& out) {
    for(map<string, LnkdLst<int> >::iterator it = m.begin();
        it != m.end(); ++it) {
        /// Print the name
        out << it->first << " ";
        //(it->second).print();
        /// Print the associated scores
        out << it->second.get(0);
        for (int i = 1; i != (it->second).getSize(); ++i) {
            out << " " << it->second.get(i);
        }
    }
    cout << endl;
}
