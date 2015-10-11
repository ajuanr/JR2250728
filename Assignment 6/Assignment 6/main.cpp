//
//  main.cpp
//  Assignment 6
//
//  Created by Juan on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// user libraries
#include "Stack.h"
#include "Queue.h"

void testStack();
void testQueue();

int main(int argc, const char * argv[]) {
    //testStack();
    testQueue();
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
}