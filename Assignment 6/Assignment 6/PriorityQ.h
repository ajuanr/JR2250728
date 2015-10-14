//
//  PriorityQ.h
//  Assignment 6
//
//  Created by Juan on 10/13/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef PriorityQ_h
#define PriorityQ_h

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
    
    void insertAfter(T);
    void prepend(T);
    
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
//        do{
//            prev=worker;
//        }while(worker=worker->next);
        // add elements with largest in the front
        if (n >= worker->data) {
            prepend(n);
        }
        else{
            cout << "Insert before\n";
            insertAfter(n);
//        Node *clink=new Node;
//        clink->data=n;
//        clink->next=NULL;
//        head=clink;
        }
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
T PriorityQ<T>::pop() {
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
    // PriorityQ was empty
    return NULL;
}



template<class T>
void PriorityQ<T>::prepend(T val) {
    cout << "in prepend\n";
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
void PriorityQ<T>::insertAfter(T n) {
    cout << "In insert before\n";
    worker = head;
    Node *prev = worker;
    while(((worker=worker->next) && (worker->next)->data > n)) {
        prev=worker->next;
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

#endif /* PriorityQ_h */
