//
//  main.cpp
//  Project
//
//  Created by Juan Ruiz on 11/7/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

/// Mac OS X 10.11.2

/// system libraries
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

/// user libraries
#include "LnkdLst.h"
#include "Minesweeper.hpp"
#include "BTree.hpp"
#include "SimpleVector.h"
#include "Queue.h"

using namespace std;

/// Typedefs
typedef map<string, LnkdLst<int> > slMap; /// string, list map

/// Functions
void analyzeMoves(Queue<int>*);
int playOnce();
void printData(const slMap&, ostream& =cout); // print previous game histories
void loadData(ifstream&, slMap&);
SimpleVector<string> split(const string&);
BTree* highScores(const slMap &);


/// hash functions stuff
int simpleHash(char c);
char getInitial(string name);
LnkdLst<string>* intoArray(const slMap&);
void printCollisions(LnkdLst<string>*);
void postGame(const slMap&);

///**************************************************************
///*************************** Main *****************************
///**************************************************************

int main(int argc, const char * argv[]) {
    cout << "MINESWEEPER\n";
    cout << "10 points for every move.\n"
        "-1 point every ten seconds.\n\n";
    cout << "Enter your name: ";
    string name;
    cin >> name;
    
    ifstream inFile("PlayerScores.txt");
    slMap lData; /// holds players' loaded data
    loadData(inFile, lData);
    inFile.close();
    
    int score = playOnce();
    lData[name].append(score);
    cout << endl;
    
    /// after games are played, save scores to the file
    ofstream outFile("PlayerScores.txt");

    if (outFile.is_open()) {
        printData(lData, outFile);
        outFile.close();
    }
    else
        cout << "File failed to open";
    
    postGame(lData);
    
    cout << endl;
    
    return 0;
}

///**************************************************************
///********************** Function Definitions ******************
///**************************************************************

/// This funtion plays Minesweeper until the player wins or loses.
/// The player score is returned
int playOnce() {
    Minesweeper *player = new Minesweeper();
    player->init();
    
    bool cont = true;
    int score =0;
    int start =time(0);
    int end = time(0);
    Queue<int> *moveTime = new Queue<int>();
    
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

void postGame(const slMap &data) {
    cout << "Would you like to see player scores? 'y' for yes: ";
    char q;
    cin >> q;
    if (q=='y') {
        cout << "Printing player scores:\n";
        printData(data);
        
        BTree *scores = highScores(data);
        cout << "list of scores sorted with binary tree:\n";
        scores->inorder();
        cout << endl;
        delete scores;
        
        cout << endl;
        
        cout << "Collisions that occur in player names\n";
        LnkdLst<string> *pScores = intoArray(data);
        printCollisions(pScores);
        
    }
}
/// Function printData prints the data in the map to the screeen or a file
void printData(const slMap& m, ostream& out) {
    for(slMap::const_iterator it = m.begin();
        it != m.end(); ++it) {
        /// Print the name
        out << it->first << " ";
        LnkdLst<int>::const_iterator lit = it->second.begin();
        out << lit->data;
        for (lit = lit->next; lit; lit=lit->next) {
            out << " " << lit->data;
        }
        out << endl;
    }
    cout << endl;
}

/// This funtion reads in previous data from a file
void loadData(ifstream& inFile, slMap& m) {
    string line;
    if (!inFile.is_open()) {
        cout << "Scores file not found\n";
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

void analyzeMoves(Queue<int>* s) {
    int total = 0;
    int n;
    int count=0;
    
    while((n=s->pop())) {
        ++count;
        total+=n;
        cout << "Move took: " << n << " seconds" << endl;
    }
    cout << "Total time is: " << (total)/60 << " minutes "
    << total%60 << " seconds\n";
    
    cout << "Average move took " << total/static_cast<float>(count)
    << " seconds\n";
}

BTree* highScores(const slMap &m) {
    BTree *out=new BTree();
    //f/ Go through each name
    for(slMap::const_iterator it = m.begin(); it != m.end(); ++it) {
        /// Go through each score
        for (LnkdLst<int>::const_iterator lit = it->second.begin();
             lit; lit = lit->next) {
            /// add the score to the set
                out->insert(lit->data);
        }
    }
    return out;
}

/// converts a letter into an int for use in an array where a list
/// of player names is located
int simpleHash(char c) {
    return c-97;
}

/// get the initial character in a name for the has function
char getInitial(string name) {
    return tolower(name[0]);
}

/// place player names into an array
LnkdLst<string>* intoArray(const slMap &data) {
    /// holds players names to be used as part of hash function
    /// lowercase letters in alphabet
    const int LOWER = 26;
    LnkdLst<string> *players  = new LnkdLst<string>[LOWER];
    for (slMap::const_iterator iter = data.begin(); iter!= data.end(); ++iter) {
         int index = simpleHash(getInitial(iter->first));
        players[index].append(iter->first);
    }
    
    return players;
}

void printCollisions(LnkdLst<string> *l) {
    /// print the list
    const int LOWER = 26;
    for (int i = 0; i != LOWER; ++i) {
        if (!l[i].empty()) {
            for(LnkdLst<string>::const_iterator it = l[i].begin();
                it; it=it->next) {
                cout << it->data << " ";
            }
            cout << endl;
        }
    }
}