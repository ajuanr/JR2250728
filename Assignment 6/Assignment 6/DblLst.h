//
//  DblList.h
//  Assignment 6
//
//  Created by Juan Ruiz on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef DblList_h
#define DblList_h


class DblLst {
public:
    DblLst(int);
    void append(int);
    string toString();
    virtual ~DblLst();
    
    string printBackwards(); // tests link to previous node
    
private:
    struct Node{
        int data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *worker;
    
    int dltHead();
};

DblLst::DblLst(int n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    clink->prev=NULL;
    head=clink;
}

void DblLst::append(int n){
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

string DblLst::toString(){
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

string DblLst::printBackwards() {
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

DblLst::~DblLst() {
    if(head){
        do{
            worker=head;
            head=head->next;
            delete worker;
        }while(head);
    }
}

#endif /* DblList_h */
