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
#include "SimpleVector.h"

using namespace std;


int playOnce();
void printData(map<string, LnkdLst<int> >&, ostream& =cout); // print previous game histories
void loadData(ifstream&, map<string, LnkdLst<int> >&);
SimpleVector<string> split(const string&);

int main(int argc, const char * argv[]) {
    cout << "Enter your name: ";
    string name;
    cin >> name;
    
    int score = playOnce();
    
    map<string, LnkdLst<int> > pData; /// holds players data
    pData[name].append(score);
    
    printData(pData);
    
    ofstream outFile("PlayerScores.txt");

    if (outFile.is_open()) {
    printData(pData, outFile);
    outFile.close();
    }
    else
        cout << "File failed to open";
    
    ////**** testing
    ifstream inFile("PlayerScores.txt");
    map<string, LnkdLst<int> > lData; /// holds players data
    loadData(inFile, lData);
    printData(lData);
    
    return 0;
}

/// This funtion plays Minesweeper until the player wins or loses.
/// The player score is returned
int playOnce() {
    Minesweeper *player = new Minesweeper();
    player->init();
    bool cont = true;
    int score =0;
    int beg = time(0);
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
    int end = time(0);
    cout << "Total time is: " << end - beg << endl;
    if (player->victory()) {
        cout << "You win!!!\n";
    }
    else cout << "You lose\n";
    
    return score;
}

/// Function printData prints the data in the map to the screeen or a file
void printData(map<string, LnkdLst<int> >& m, ostream& out) {
    for(map<string, LnkdLst<int> >::iterator it = m.begin();
        it != m.end(); ++it) {
        /// Print the name
        out << it->first << " ";
        //(it->second).print();
        /// Print the associated scores
        out << it->second.get(0);
        for (int i = 1; i != it->second.getSize(); ++i) {
            out << " " << it->second.get(i);
        }
    }
    cout << endl;
}

/// This funtion read in previous data from a file
void loadData(ifstream& inFile, map<string, LnkdLst<int> >& m) {
    string line;
    if (!inFile.is_open()) {
        cout << "Error reading file\n";
        return;
    }
    SimpleVector<string> temp;
    while (getline(inFile, line)) {
        temp = split(line);
        /// load the name into the map
        m[temp[0]];
        for(int i = 1; i != temp.size(); ++i) {
            cout << temp[0] << endl;
            //int num = atoi(temp[i]);
            //cout << num << endl;//m[temp[0]].append(stoi(temp[i]));
        }
    }
}

/// Function splits seperates each word sepereated by a space
/// and returns the individual componenets in a vector
SimpleVector<string> split(const string& s) {
    SimpleVector<string> out;
    
    typedef string::const_iterator cit;
    cit  begin= s.begin(); /// This marks the beginning of the line/word
    cit end = s.begin();
    for(cit it = s.begin(); it != s.end(); ++it) {
        /// this marks the end of the word
        if (isspace(*it)) {
            end = it;
            out.push_back(string(begin, end)); /// create a new string and push it back
        }
        if(end>begin && !isspace(*it)) {
            begin = it;
        }
    }
    /// acount for last word because there are no spaces if string ends
    end = s.end();
//    if(!isspace(*end)) {
        out.push_back(string(begin, end)); /// create a new string and push it back
//    cout << "Begin is: " << *begin << endl << "End is: " << *end<< endl;
    
    return out;
}
