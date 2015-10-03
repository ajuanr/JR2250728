//
//  VecLst.hpp
//  LinkedList
//
//

#ifndef VecLst_hpp
#define VecLst_hpp

#include <stdio.h>

#include <string>
using namespace std;

class VecLst {
public:
    VecLst();
    VecLst(int);
    void append(int);
    string toString();
    virtual ~VecLst();
    
    
    void dltLast();
    void dltHead();
    void remove(int);
    int getSize(){return size;}
    int& getElementAt(int);
    int& operator[](int n) { return getElementAt(n);}
private:
    struct Node{
        int data;
        Node *next;
    };
    Node *head;
    Node *worker;
    int size;
    
    //******************************
    //***** Utility functions *******
    ////////////////////////////////
    void dltCurrent(Node *);
    void dltMid(Node *);
};

#endif /* VecLst_hpp */
