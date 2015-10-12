//
//  DblList.h
//  Assignment 6
//
//  Created by Juan Ruiz on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef DblList_h
#define DblList_h

template<class T>
class DblLst {
public:
    DblLst(T);
    void append(T);
    string toString();
    virtual ~DblLst();
    
    string printBackwards(); // tests link to previous node
    
private:
    struct Node{
        T data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *worker;
    
    int dltHead();
};

template<class T>
DblLst<T>::DblLst(T n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    clink->prev=NULL;
    head=clink;
}

template<class T>
void DblLst<T>::append(T n){
    if(head){
        Node *ante;
        worker=head;
        do{
            ante=worker;
        }while(worker=worker->next);
        Node *clink=new Node;
        clink->data=n;
        clink->next=NULL;
        clink->prev=ante;
        ante->next=clink;
    }else{
        Node *clink=new Node;
        clink->data=n;
        clink->next=NULL;
        clink->prev=NULL;
        head=clink;
    }
}

template<class T>
string DblLst<T>::toString(){
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
string DblLst<T>::printBackwards() {
    string build="";
    if (head) {
        Node *ante;
        worker=head;
        // find end of list
        do {
            ante=worker;
        }while(worker=worker->next);
        worker=ante;
        do {
            build+=("Data element in the list ->");
            stringstream ss;
            ss<<worker->data;
            string data;
            ss>>data;
            build+=data;
            build+="\n";
        }while(worker=worker->prev);
    }
    return build;
}

template<class T>
DblLst<T>::~DblLst() {
    if(head){
        do{
            worker=head;
            head=head->next;
            delete worker;
        }while(head);
    }
}

#endif /* DblList_h */
