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
#include <set>
#include <string>
#include <sstream>

/// user libraries
#include "LnkdLst.hpp"
#include "Minesweeper.hpp"
#include "Stack.h"
#include "SimpleVector.h"

using namespace std;

/// Typedefs
typedef map<string, LnkdLst<int> > svMap;

/// Functions
void analyzeMoves(Stack<int>*);
int playOnce();
void printData(svMap&, ostream& =cout); // print previous game histories
void loadData(ifstream&, svMap&);
SimpleVector<string> split(const string&);
set<int> highScores(svMap &m);
void printSet(const set<int>& s);

int main(int argc, const char * argv[]) {
    cout << "Enter your name: ";
    string name;
    cin >> name;
    
    ifstream inFile("PlayerScores.txt");
    svMap lData; /// holds players data
    loadData(inFile, lData);
    inFile.close();
    
    int score = playOnce();
    lData[name].append(score);
    
    /// after games are played, save scores to the file
    ofstream outFile("PlayerScores.txt");

    if (outFile.is_open()) {
    printData(lData, outFile);
    outFile.close();
    }
    else
        cout << "File failed to open";
    
    printData(lData);
    
    set<int> scores = highScores(lData);
    printSet(scores);
    
    return 0;
}

/// This funtion plays Minesweeper until the player wins or loses.
/// The player score is returned
int playOnce() {
    Minesweeper *player = new Minesweeper();
    player->init();
    
    bool cont = true;
    int score =0;
    int start =time(0);
    int end = time(0);
    Stack<int> *moveTime = new Stack<int>();
    
    while(cont){
        int beg = time(0);
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
        end = time(0);
        moveTime->push(end-beg);
    }

    if (player->victory()) {
        cout << "You win!!!\n";
    }
    else cout << "You lose\n";
    
    cout << "***Some game data***\n";
    analyzeMoves(moveTime);
    score -= (end-start)/10;
    
    delete moveTime;
    delete player;
    /// don't allow score to go negative
    if(score<0) score=0;
    cout << "Your score is: " << score << endl;
    return score;
}

/// Function printData prints the data in the map to the screeen or a file
void printData(svMap& m, ostream& out) {
    for(svMap::iterator it = m.begin();
        it != m.end(); ++it) {
        /// Print the name
        out << it->first << " ";
        /// Print the associated scores
        out << it->second.get(0);
        for (int i = 0; i != it->second.getSize(); ++i) {
            out << " " << it->second.get(i);
        }
        out << endl;
    }
    cout << endl;
}

/// This funtion reads in previous data from a file
void loadData(ifstream& inFile, svMap& m) {
    string line;
    if (!inFile.is_open()) {
        cout << "Error reading file\n";
        return;
    }
    
    while (getline(inFile, line)) {
        SimpleVector<string> temp(split(line));
        /// load the name into the map
        m[temp[0]];
        for(int i = 1; i != temp.size(); ++i) {
            istringstream is(temp[i]);
            int num;
            is>>num;
            m[temp[0]].append(num);
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
    out.push_back(string(begin, end)); /// create a new string and push it back
    
    return out;
}

void analyzeMoves(Stack<int>* s) {
    int total = 0;
    int n;
    int count=0;
    
    while(n=s->pop()) {
        ++count;
        total+=n;
        cout << "Move took: " << n << " seconds" << endl;
    }
    cout << "Total time is: " << (total)/60 << " minutes "
    << total%60 << " seconds\n";
    
    cout << "Average move took " << total/static_cast<float>(count)
    << " seconds\n";
}

set<int> highScores(svMap &m) {
    set<int> out;
    /// Go through each name
    for(svMap::iterator it = m.begin(); it != m.end(); ++it) {
        /// Go through each score
        for(int i = 0; i != it->second.getSize(); ++i) {
            /// add that score to the set
            out.insert(it->second.get(i));
        }
    }
    return out;
}

void printSet(const set<int>& s) {
    for (set<int>::const_iterator cit = s.begin(); cit != s.end(); ++cit){
        cout << *cit << " ";
    }
    cout << endl;
}
