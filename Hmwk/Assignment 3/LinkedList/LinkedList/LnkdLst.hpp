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
    LnkdLst(int);
    void append(int);
    string toString();
    virtual ~LnkdLst();
    
    
    void dltLast();
    void dltHead();
    
    void testDltLast();
    
    void remove(int);
private:
    struct Node{
        int data;
        Node *next;
    };
    Node *head;
    Node *worker;
    
    void dltCurrent(Node *);
    void dltMid(Node *);

    

};

#endif /* LnkdLst_hpp */
