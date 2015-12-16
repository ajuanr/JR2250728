//
//  Queue.h
//  Assignment 6
//
//  Created by Juan on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <string>
#include <sstream>

using namespace std;

template<class T>
class Queue {
public:
    Queue(){}
    Queue(T);
    void push(T);
    T pop();
    string toString();
    virtual ~Queue();
    
private:
    struct Node{
        T data;
        Node *next;
    };
    Node *head;
    
};

template<class T>
Queue<T>::Queue(T n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    head=clink;
}

template<class T>
void Queue<T>::push(T n){
    Node *prev;
    if(head){
        Node *worker=head;
        do{
            prev=worker;
        }while(worker=worker->next);
        Node *clink=new Node;
        clink->data=n;
        clink->next=NULL;
        prev->next=clink;
    }else{
        Node *clink=new Node;
        clink->data=n;
        clink->next=NULL;
        head=clink;
    }
}

template<class T>
Queue<T>::~Queue() {
    if(head){
        Node* worker = head;
        do{
            worker=head;
            head=head->next;
            delete worker;
        }while(head);
    }
}

template<class T>
T Queue<T>::pop() {
    // head is not the only node
    if(head) {
        Node* worker=head;
        T temp=worker->data;
        // list has at least two nodes
        if(head->next) {
            head = worker->next;
            delete worker;
        }
        // head is the only node
        else {
            delete head;
            head=NULL;
        }
        return temp;
    }
    // Queue was empty
    return NULL;
}

#endif /* Queue_h */
