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
    LnkdLst(LnkdLst&); // copy constructor
    void append(int);
    void prepend(int);
    string toString();
    virtual ~LnkdLst();
    
    
    
    void dltLast();
    void dltHead();
    void remove(int);
    int getSize(){return size;}
    int& get(int);
    //int& operator[](int n) { return get(n);}
    
    int& first() {return get(0);}
    int& last() {return get(size-1);}
    void insertBefore(int, int);
    void insertAfter(int, int);
    
    void print();
    
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
