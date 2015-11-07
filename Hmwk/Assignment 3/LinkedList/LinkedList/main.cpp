//
//  main.cpp
//  LinkedList
//
//

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "LnkdLst.hpp"

int main(int argc, char** argv) {
    //Create a linked list
    LnkdLst list(0);
    //Append 10 more chains
    int clinks=10;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    
    list.remove(10);

    //Print the data
    cout<<list.toString()<<endl;
    //Exit stage right!
    return 0;
}
