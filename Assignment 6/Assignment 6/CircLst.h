//
//  CircLst.h
//  Assignment 6
//
//  Created by Juan Ruiz on 10/11/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef CircLst_h
#define CircLst_h

class CircLst {
public:
    CircLst(int);
    void append(int);
    string toString();
    virtual ~CircLst();
    
    
    void dltLast();
    void dltHead();
    
    void testDltLast();
    
    void remove(int);
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
    clink->next=head;
    head=clink;
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
        clink->next=NULL;
        prev->next=clink;
    }else{
        Node *clink=new Node;
        clink->data=n;
        clink->next=NULL;
        head=clink;
    }
}


#endif /* CircLst_h */
