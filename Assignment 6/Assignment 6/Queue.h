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
    Node *worker;
    
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
string Queue<T>::toString(){
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
Queue<T>::~Queue() {
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
T Queue<T>::pop() {
    // head is not the only node
    if(head) {
        worker=head;
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
