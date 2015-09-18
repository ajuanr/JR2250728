//
//  D2Array.h
//  D1Array
//
//  Created by Juan Ruiz on 9/3/15.
//  Copyright (c) 2015 Juan Ruiz. All rights reserved.
//

#ifndef __D2Array__
#define __D2Array__

// System libraries
#include <iostream>
#include <cstdlib>

// User libraries
#include "D1Array.h"

template <class T>
class D2Array {
private:
    void fill();
    T **data;
    D1Array<int> d1ary;
    int cols;
    
public:
    D2Array(int);
    ~D2Array();

    void print() const;
};

using namespace std;

// constructor
template <class T>
D2Array<T>::D2Array(int n)
:cols(n), d1ary(n){
    fill();
}

template<class T>
D2Array<T>::~D2Array() {
    for(int i=0;i<cols;i++){
        delete [] data[i];
    }
    delete []data;
}

template<class T>
void D2Array<T>::fill() {
    //Allocates Memory
    data=new T*[cols];
    for(int i=0;i<cols;i++){
        data[i]=new T[d1ary[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<cols;row++){
        for(int col=0;col<d1ary[row];col++){
            data[row][col]=rand()%90+10;
        }
    }
}

template <class T>
void D2Array<T>::print() const {
    //Print the allocated memory
    for(int row=0;row<cols;row++){
        for(int col=0;col<d1ary[row];col++){
            cout<<data[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}

#endif /* defined(__D1Array__D2Array__) */
