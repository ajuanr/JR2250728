//
//  DblList.h
//  Assignment 6
//
//  Created by Juan Ruiz on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef DblList_h
#define DblList_h


class DblList {
public:
    DblList(int);
    void append(int);
    string toString();
    virtual ~DblList();
    
private:
    struct Node{
        int data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *worker;
    
    int dltHead();
};

#endif /* DblList_h */
