//
//  PriorityQ.h
//  Assignment 6
//
//  Created by Juan on 10/14/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef PriorityQ_h
#define PriorityQ_h

#include <string>
#include <sstream>

using namespace std;

template<class T>
class PriorityQ {
public:
    PriorityQ(T);
    void push(T);
    T pop();
    string toString();
    virtual ~PriorityQ();
    
private:
    struct Node{
        T data;
        Node *next;
    };
    Node *head;
    Node *worker;
    
    // utility functions
    T findMax();
    T dltNode(T);
};

template<class T>
PriorityQ<T>::PriorityQ(T n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    head=clink;
}

template<class T>
void PriorityQ<T>::push(T n){
    Node *prev;
    if(head){
        worker=head;
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
string PriorityQ<T>::toString(){
    string build="";
    char counter=48;
    if(head){
        worker=head;
        do{
            build+=("Data element in the list ->");
            stringstream ss;
            ss<<worker->data;
            string data;
            ss>>data;
            build+=data;
            build+="\n";
        }while(worker=worker->next);
    }
    return build;
}

template<class T>
PriorityQ<T>::~PriorityQ() {
    if(head){
        worker = head;
        do{
            worker=head;
            head=head->next;
            delete worker;
        }while(head);
    }
}

template<class T>
T PriorityQ<T>::findMax() {
    T max = head->data;
    worker=head;
    Node *prev=worker;
    while (worker) {
        if ((worker->data) >= max) {
            max = worker->data;
        }
        prev=worker;
        worker=worker->next;
    }
    cout << "Max is: " << max << endl;
    return max;
}

template<class T>
T PriorityQ<T>::dltNode(T max) {
    worker = head;
    Node *prev = worker;
    while ((worker->data) != max) {
        prev = worker;
        worker = worker->next;
    }
    T temp = worker->data;
    // worker is head
    if (prev == head) {
        head = worker->next;
        delete worker;
    }
    // head is last element
    else if (!(worker->next)) {
        prev->next = NULL;
    }
    // worker is in the middle somewhere
    else {
        prev->next = worker->next;
        delete worker;
    }
    return temp;
}


template<class T>
T PriorityQ<T>::pop() {
    // head is not the only node
    if(head) {
        worker=head;
        T temp;//=worker->data;
        // list has at least two nodes
        if(head->next) {
            // remove the node with greatest value(highest priority)
            temp = dltNode(findMax());
        }
        // head is the only node
        else {
            delete head;
            head=NULL;
        }
        return temp;
    }
    // PriorityQ was empty
    return NULL;
}

#endif /* PriorityQ_h */
