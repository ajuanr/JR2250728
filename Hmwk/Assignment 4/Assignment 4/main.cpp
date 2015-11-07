//
//  main.cpp
//  Assignment 4
//
//  Created by Juan Ruiz on 10/1/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <cstdlib>


// user libraries
#include "VecLst.hpp"

void print(VecLst*, int);

int main(int argc, const char * argv[]) {
    cout << "Create vector with 1 element\n";
    VecLst *vl = new VecLst(5);
    cout << "size of vector: " << vl->getSize() << endl;
    cout << "elements in vector: ";
    print(vl, vl->getSize());
    cout << "Delete only element in vector.\n";
    vl->dltLast();
    cout << "size of vector: " << vl->getSize() << endl;
    
    cout << "Add 10 elements\n";
    for (int i = 0; i != 10; ++i) {
        vl->append(rand()%10);
    }
    cout << "New size of vector: " << vl->getSize() << endl;
    cout << "elements in vector: ";
    print(vl, vl->getSize());
    
    cout << "Remove instances of the number 9\n";
    vl->remove(9);
    cout << "New size of vector: " << vl->getSize() << endl;
    cout << "elements in vector: ";
    print(vl, vl->getSize());
    
    cout << "Delete the head\n";
    vl->dltHead();
    cout << "New size of vector: " << vl->getSize() << endl;
    cout << "elements in vector: ";
    print(vl, vl->getSize());
    
    cout << "Pop last element off:\n";
    vl->dltLast();
    cout << "New size of vector: " << vl->getSize() << endl;
    cout << "elements in vector: ";
    print(vl, vl->getSize());

    delete vl;
    
    return 0;
}

void print(VecLst *vl, int size) {
    for (int i = 0; i != size; ++i) {
        cout << vl[0][i] <<  " ";
    }
    cout << endl << endl;
}