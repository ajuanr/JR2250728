//
//  SrtdLst.h
//  Assignment 6
//
//  Created by Juan on 10/13/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef SrtdLst_h
#define SrtdLst_h

using namespace std;

template<class T>
class SrtdLst {
public:
    SrtdLst(T);
    void push(T);
    T pop();
    string toString();
    virtual ~SrtdLst();
    
private:
    struct Node{
        T data;
        Node *next;
    };
    Node *head;
    Node *worker;
    
    void insertAfter(T);
    void prepend(T);
    
};

template<class T>
SrtdLst<T>::SrtdLst(T n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    head=clink;
}

template<class T>
void SrtdLst<T>::push(T n){
    Node *prev;
    if(head){
        worker=head;

        if (n >= worker->data) {
            prepend(n);
        }
        else{
            insertAfter(n);
        }
    }
}

template<class T>
string SrtdLst<T>::toString(){
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
SrtdLst<T>::~SrtdLst() {
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
T SrtdLst<T>::pop() {
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
    // SrtdLst was empty
    return NULL;
}



template<class T>
void SrtdLst<T>::prepend(T val) {
    if (head) {
        Node *clink = new Node;
        clink->data=val;
        clink->next = head;
        head = clink;
    }else{
        Node *clink=new Node;
        clink->data=val;
        clink->next=NULL;
        head=clink;
    }
}

template<class T>
void SrtdLst<T>::insertAfter(T n) {
    worker = head;
    Node *prev = worker;
    while(((worker=worker->next) && (worker->data) > n)) {
        prev=worker;
    }
    if(prev->next) {
            Node *clink=new Node;
            clink->data=n;
            clink->next=worker;
            prev->next=clink;
    } else {
                Node *clink=new Node;
                clink->data=n;
                clink->next=NULL;
    }
}

#endif /* SrtdLst_h */
