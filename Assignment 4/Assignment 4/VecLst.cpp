//
//  VecLst.cpp
//  LinkedList
//
//

#include "VecLst.hpp"

#include <sstream>

#include <iostream>

VecLst::VecLst(int n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    head=clink;
    size = 1;
}

void VecLst::append(int n){
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

string VecLst::toString(){
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

VecLst::~VecLst() {
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
VecLst::VecLst() {
    head=NULL;
}

void VecLst::dltHead() {
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

void VecLst::dltCurrent(Node *current) {
    // current is the head
    if (head) {
        if (current == head) dltHead();
        else if (!current->next) dltLast();
        else dltMid(current);
        --size;
    }
}

void VecLst::dltLast() {
    if (head) {
        Node *prev = head;
        worker = head;
        while (worker=worker->next) {
            if (worker->next) prev=worker;
        }
        // last node is the only node
        if (prev == head && !prev->next) {
            dltHead();
            size = 88;
        }
        else {
            prev->next=NULL;
            delete worker;
            --size;
        }
    }
}

//******************************************************
// ** delete a node that's not the head or the last node
// ** won't work for head or last node *****************
//******************************************************
void VecLst::dltMid(Node *mid) {
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
// *** Function removes first instance of n ****
//**********************************************
void VecLst::remove(int n) {
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

int& VecLst::getElementAt(int n) {
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