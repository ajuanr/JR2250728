//
//  LnkdLst.cpp
//  LinkedList
//
//

#include "LnkdLst.hpp"

#include "LnkdLst.hpp"
#include <sstream>

#include <iostream>

LnkdLst::LnkdLst(int n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    head=clink;
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
    }else{
        Node *clink=new Node;
        clink->data=n;
        clink->next=NULL;
        head=clink;
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
    }
}

//*****************************************************
//** These functions added as part of the homework ****
//*****************************************************

void LnkdLst::dltHead() {
    // head is not the only node
    if(head) {
        worker=head;
        // list has at least two nodes
        if(head->next) {
            head = head->next;
            delete worker;
        }
        // has is the only node
        else {
            delete head;
            head=NULL;
        }
    }
        }

void LnkdLst::dltCurrent(Node *current) {
    // current is the head
    if (head) {
        if (current == head) dltHead();
        else if (!current->next) dltLast();
        else dltMid(current);
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
        if (prev == head) {
            dltHead();
        }
        else {
            prev->next=NULL;
            delete worker;
        }
    }
}

//******************************************************
// ** delete a node that's not the head or the last node
// ** won't work for head or last node *****************
//******************************************************
void LnkdLst::dltMid(Node *mid) {
    if (head) {

        // make sure it's between two nodes
        if (mid->next && mid !=head) {
            worker = mid->next;
        
            mid->data = worker->data;
            mid->next = worker->next;
        
            delete worker;
        }
    }
}

//**********************************************
// *** Function removes first instance of n ****
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