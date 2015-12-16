//
//  Stack.h
//  Assignment 6
//
//  Created by Juan on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <string>
#include <sstream>

using namespace std;

template<class T>
class Stack {
public:
    Stack(){};
    Stack(T);
    void push(T);
    T pop();
    string toString();
    virtual ~Stack();

private:
    struct Node{
        T data;
        Node *next;
    };
    Node *head;

    T dltHead();
};

/// Constructor with T value
template<class T>
Stack<T>::Stack(T n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    head=clink;
}

template<class T>
void Stack<T>::push(T n){
    Node *prev;
    if(head){
        Node* worker=head;
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
string Stack<T>::toString(){
    string build="";
    char counter=48;
    if(head){
        Node* worker=head;
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
Stack<T>::~Stack() {
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
T Stack<T>::dltHead() {
    // head is not the only node
    if(head) {
        Node* worker=head;
        T temp=worker->data;
        // list has at least two nodes
        if(head->next) {
            head = head->next;
            delete worker;
        }
        // head is the only node
        else {
            delete head;
            head=NULL;
        }
        return temp;
    }
    // stack was empty
    return NULL;
}

template<class T>
T Stack<T>::pop() {
    if (head) {
        T temp;
        Node *prev = head;
        Node* worker = head;
        while (worker=worker->next) {
            if (worker->next) prev=worker;
        }
        // last node is the only node
        if (prev == head) {
            temp = dltHead();
        }
        else {
            temp = prev->data;
            prev->next=NULL;
            delete worker;
        }
        return temp;
    }
    return NULL;
}

#endif /* Stack_h */
