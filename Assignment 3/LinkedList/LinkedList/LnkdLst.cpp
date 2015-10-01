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

void LnkdLst::dltLast(Node *penult) {
    Node *temp = penult->next;
    delete temp;
    penult->next=NULL;
}

void LnkdLst::testDltLast() {
        Node *prev;
        if(head){
            worker=head;
            while(worker-worker->next) { prev=worker;}
            cout << prev->data << " DATA" << endl;
        }
    dltLast(prev);
}

// delete a node that's not the head or the last node
void LnkdLst::dltMid(Node *mid) {
    // make sure it's between two nodes
    if (mid->next && mid!=head) {
        Node *temp = mid->next;
        
        mid->data = temp->data;
        mid->next = temp->next;
        
        delete temp;
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
            cout << worker->data << endl;
            prev=worker;
            if (worker && worker->data==n) {found=true;}

        } while((worker=worker->next) && !found);
        if (found) { cout << "Found\n";}
    }
}