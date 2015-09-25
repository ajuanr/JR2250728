//
//  LnkdLst.cpp
//  LinkedList
//
//

#include "LnkdLst.hpp"

#include "LnkdLst.hpp"
#include <sstream>


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


