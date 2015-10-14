//
//  main.cpp
//  Assignment 6
//
//  Created by Juan on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// user libraries
#include "Stack.h"
#include "Queue.h"
#include "DblLst.h"
#include "CircLst.h"
#include "PriorityQ.h"

void testStack();
void testQueue();
void testDblList();
void testCircLst();
void testPriorityQ();

int main(int argc, const char * argv[]) {
    // seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    //testStack();
    //testQueue();
    //testDblList();
//    testCircLst();
    testPriorityQ();
    return 0;
}

void testStack() {
    cout << "Create new stack\n";
    Stack<string> *s = new Stack<string>("This");
    cout << s->toString() << endl;
    
    cout << "Push onto stack\n";
    s->push("is");
    s->push("working");
    cout << s->toString();
    cout << endl;
    
    cout << "Pop an element\n";
    s->pop();
    cout << s->toString();
    cout << endl;
    
    delete s;
}


void testQueue() {
    cout << "Create new queue\n";
    Queue<string> *q = new Queue<string>("This");
    cout << q->toString() << endl;
    
    cout << "Push onto queue\n";
    q->push("is");
    q->push("working");
    cout << q->toString();
    cout << endl;
    
    cout << "Pop an element\n";
    q->pop();
    cout << q->toString();
    cout << endl;
    
    delete q;
}

void testDblList() {
    cout << "Create a new doubly linked list\n";
    DblLst<int> *db = new DblLst<int>(rand()%100+1);
    for (int i = 0; i != 4; ++i)
        db->append(rand()%100+1);
    cout << db->toString();
    cout << "\nTraverse the doubly linked list in reverse order\n";
    cout << db->printBackwards();
    cout << endl;
    
    delete db;
}

void testCircLst() {
    cout << "Create a circularly linked list\n";
    CircLst *cLst = new CircLst(rand()%100+1);
    cout << cLst->toString();
    
    cout << "Append to the list\n";
    for (int i = 0; i != 2; ++i)
        cLst->append(rand()%100+1);
    cout << cLst->toString();
    
    delete cLst;
}

void testPriorityQ() {
    cout << "Create a new priority queue\n";
        PriorityQ<int> *pq = new PriorityQ<int>(5);
    cout << "Append some data\n";
    for (int i = 0; i !=5; ++i) {
        pq->push(rand()%20+1);
    }
    cout <<pq->toString();
}