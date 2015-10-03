//
//  LnkdLst.hpp
//  LinkedList
//
//

#ifndef LnkdLst_hpp
#define LnkdLst_hpp

#include <stdio.h>

#include <string>
using namespace std;

class LnkdLst {
public:
    LnkdLst();
    LnkdLst(int);
    void append(int);
    string toString();
    virtual ~LnkdLst();
    
    
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

#endif /* LnkdLst_hpp */
