//
//  CircLst.h
//  Assignment 6
//
//  Created by Juan Ruiz on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef CircLst_h
#define CircLst_h

#include <string>
#include <sstream>
using namespace std;

class CircLst {
public:
    CircLst(int);
    void append(int);
    string toString();
    virtual ~CircLst();
    
    
//    void dltLast();
//    void dltHead();
    
//    void remove(int);
private:
    struct Node{
        int data;
        Node *next;
    };
    Node *head;
    Node *worker;
};

CircLst::CircLst(int n) {
    Node *clink=new Node;
    clink->data=n;
    head=clink;
    clink->next=head;
}

void CircLst::append(int n){
    Node *prev;
    if(head){
        worker=head;
        do{
            prev=worker;
        }while((worker=worker->next) !=head);
        Node *clink=new Node;
        clink->data=n;
        clink->next=head;
        prev->next=clink;
    }else{
        Node *clink=new Node;
        clink->data=n;
        clink->next=NULL;
        head=clink;
    }
}

string CircLst::toString(){
    string build="";
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
            worker=worker->next;
        }while(worker!=head);
    }
    return build;
}

CircLst::~CircLst() {
    if(head){
        worker = head->next;
        Node *post = worker;
        
        while (worker != head) {
            post = post->next;
            delete worker;
            worker = post;
        }
        // delete the head last
        delete head;
        
    }
}

#endif /* CircLst_h */
