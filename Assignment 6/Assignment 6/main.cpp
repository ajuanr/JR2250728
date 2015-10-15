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
#include "SrtdLst.h"
#include "PriorityQ.h"


void Menu();
int getN();
void def(int);
void testStack();
void testQueue();
void testDblList();
void testCircLst();
void testSrtdLst();
void testPriorityQ();

int main(int argc, const char * argv[]) {
    // seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    testStack();;cout << endl;break;
            case 2:    testQueue();cout << endl;break;
            case 3:    testDblList();cout << endl;break;
            case 4:    testCircLst();cout << endl;break;
            case 5:    testSrtdLst();cout << endl;break;
            case 6:    testPriorityQ();cout << endl;break;
            default:   def(inN);
        }
    } while(inN<7);
    return 0;
}

void Menu()
{
    cout<<"Type 1 to look at stack"<<endl;
    cout<<"Type 2 to look at queue"<<endl;
    cout<<"Type 3 to look at doubly linked list"<<endl;
    cout<<"Type 4 to look at circularly linked list"<<endl;
    cout<<"Type 5 to look at sorted list"<<endl;
    cout<<"Type 6 to look at priority queue"<<endl;
    cout<<"Type 7 to exit \n"<<endl;
}
int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN)
{
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
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

void testSrtdLst() {
    cout << "Create a new priority queue\n";
        SrtdLst<int> *pq = new SrtdLst<int>(5);
    cout << "Append some data\n";
    for (int i = 0; i !=5; ++i) {
        pq->push(rand()%20+1);
    }
    cout <<pq->toString() << endl;
}

void testPriorityQ() {
    cout << "Create new priority queue\n";
    PriorityQ<int> *pq = new PriorityQ<int>(12);
    cout << pq->toString() << endl;
    cout << "Append some data\n";
    for (int i = 0; i !=5; ++i) {
        pq->push(rand()%50+1);
    }
    cout <<pq->toString() << endl;
    cout << "Remove nodes with highest priority\n";
    cout << "Popped: " << pq->pop() << endl;
    cout << "Popped: " << pq->pop() << endl;
    cout << "Popped: " << pq->pop() << endl;
    cout << endl;
    cout << "Remaining nodes\n";
    cout << pq->toString() << endl;;
}