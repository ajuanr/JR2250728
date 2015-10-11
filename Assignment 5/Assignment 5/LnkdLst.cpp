//
//  LnkdLst.cpp
//  LinkedList
//
//

#include "LnkdLst.hpp"

#include <sstream>

#include <iostream>

LnkdLst::LnkdLst(int n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    head=clink;
    size = 1;
}

LnkdLst::LnkdLst(LnkdLst& lst) {
    Node *headLnk=new Node;
    headLnk->data=lst.get(0);
    headLnk->next=NULL;
    head=headLnk;
    size = 1;
    lst.worker = lst.head;
    this->worker = this->head;
    while (lst.worker = lst.worker->next) {
        Node *clink = new Node;
        clink->data = lst.worker->data;
        clink->next = NULL;
        this->worker->next = clink;
        this->worker = worker->next;
        ++size;
    }
}

void LnkdLst::append(int n){
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
        ++size;
    }else{
        Node *clink=new Node;
        clink->data=n;
        clink->next=NULL;
        head=clink;
        size=1;
    }
}

string LnkdLst::toString(){
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

LnkdLst::~LnkdLst() {
    if(head){
        worker = head;
        do{
            worker=head;
            head=head->next;
            delete worker;
        }while(head);
        size = 0;
    }
}

//*****************************************************
//** These functions added as part of the homework ****
//*****************************************************

//*****************************************************
//** Default constructor ****
//*****************************************************
LnkdLst::LnkdLst() {
    head=NULL;
}

void LnkdLst::dltHead() {
    // head is not the only node
    if(head) {
        worker=head;
        // list has at least two nodes
        if(head->next) {
            head = head->next;
            delete worker;
            --size;
        }
        // head is the only node
        else {
            delete head;
            head=NULL;
            size=0;
        }
    }
        }


//**************************************************************
// ** function dltCurrent deletes the node passed in ***********
// ** Check the position of the node to ensure proper deletion *
//**************************************************************
void LnkdLst::dltCurrent(Node *current) {
    // current is the head
    if (head) {
        if (current == head) dltHead();
        else if (!current->next) dltLast();
        else dltMid(current);
        --size;
    }
}

void LnkdLst::dltLast() {
    if (head) {
        Node *prev = head;
        worker = head;
        while (worker=worker->next) {
            if (worker->next) prev=worker;
        }
        // last node is the only node
        if (prev == head && !prev->next) {
            dltHead();
            size = 0;
        }
        else {
            prev->next=NULL;
            delete worker;
            --size;
        }
    }
}

//********************************************************
// ** delete a node that's not the head or the last node *
// ** won't work for head or last node *******************
//********************************************************
void LnkdLst::dltMid(Node *mid) {
    if (head) {
        // make sure it's between two nodes
        if (mid->next && mid !=head) {
            worker = mid->next;
        
            mid->data = worker->data;
            mid->next = worker->next;
        
            delete worker;
        }
        --size;
    }
}

//**********************************************
// *** Function remove, first instance of n ****
//**********************************************
void LnkdLst::remove(int n) {
    Node *prev;
    if(head){
        worker=head;
        bool found=false;;
        do{
            prev=worker;
            if (worker && worker->data==n) {found=true;}

        } while((worker=worker->next) && !found);
        if (found) {
            dltCurrent(prev);
//            if (prev == head) dltHead();
//            else if (!prev->next) dltLast();
//            else dltMid(prev);
        }
    }
}

//*********************************************************
// ** function get, returns the data in the node passed in *
//*********************************************************
int& LnkdLst::get(int n) {
    if (n>=0 && n<size) {
        if (head) {
            worker=head;
            for (int i = 0; i != n; i++) {
                worker=worker->next;
            }
            
            return worker->data;
        }
    }
    return head->data;
}


void LnkdLst::insertBefore(int index, int val) {
    if (head) {
        Node *prev;
        worker = head;
        // index out of range
        if(index>=this->size || index < 0) return;
        if(index==0) { prepend(val); }
        else {//if(index>0 && index<size) {
            int i = 0;
            do {
                prev = worker;
                worker=worker->next;
                ++i;
            } while (i!=index);
            Node *clink = new Node;
            clink->data = val;
            clink->next = prev->next;
            prev->next=clink;
            ++size;
        }
    }
}

void LnkdLst::insertAfter(int index, int val) {
    if (head) {
        // trying to insert out of range
        if(index>=this->size || index < 0) return;
        
        if (index==(size-1)) {append(val);}
        else {insertBefore(index+1, val);}
    }
}

void LnkdLst::prepend(int val) {
    if (head) {
        Node *clink = new Node;
        clink->data=val;
        clink->next = head;
        head = clink;
        ++size;
    }else{
        Node *clink=new Node;
        clink->data=val;
        clink->next=NULL;
        head=clink;
        size=1;
    }
}

void LnkdLst::print() {
    if (head) {
        Node *prev;
        worker=head;
        do {
            prev=worker;
            cout << prev->data << " ";
        } while (worker=worker->next);
    cout << endl;
    }
}