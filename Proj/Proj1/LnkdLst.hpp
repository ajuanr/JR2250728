//
//  LnkdLst.hpp
//  LinkedList
//
//

#ifndef LnkdLst_hpp
#define LnkdLst_hpp

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template<class T>
class LnkdLst {
public:
    LnkdLst();
    LnkdLst(T);
    LnkdLst(const LnkdLst&); // copy constructor
    void append(T);
    void prepend(T);
    string toString();
    virtual ~LnkdLst();

    void dltLast();
    void dltHead();
    void remove(T);
    int getSize(){return size;}
    T& get(int);
    //int& operator[](int n) { return get(n);}
    
    int& first() {return get(0);}
    int& last() {return get(size-1);}
    void insertBefore(int, T);
    void insertAfter(int, T);
    T extract(int);
    
    bool empty() { return !head;}
    void print();
    void sort();
    
    LnkdLst& operator=(LnkdLst&);
    
private:
    struct Node{
        T data;
        Node *next;
    };
    Node *head;
    Node *worker;
    int size;
    
    //******************************
    //***** Utility functions *******
    ////////////////////////////////
    void dltCurrent(Node *);
    void dltMid(Node *);
};

#endif /* LnkdLst_hpp */

template<class T>
LnkdLst<T>::LnkdLst(T n) {
    Node *clink=new Node;
    clink->data=n;
    clink->next=NULL;
    head=clink;
    size = 1;
}


/// The copy constructor
template<class T>
LnkdLst<T>::LnkdLst(const LnkdLst& lst) {
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
template<class T>
void LnkdLst<T>::append(T n){
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

template<class T>
string LnkdLst<T>::toString(){
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
LnkdLst<T>::~LnkdLst() {
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
//** Default constructor ****
//*****************************************************
template<class T>
LnkdLst<T>::LnkdLst() {
    head=NULL;
    size=0;
    
}
template<class T>
void LnkdLst<T>::dltHead() {
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
template<class T>
void LnkdLst<T>::dltCurrent(Node *current) {
    // current is the head
    if (head) {
        if (current == head) dltHead();
        else if (!current->next) dltLast();
        else dltMid(current);
        --size;
    }
}

template<class T>
void LnkdLst<T>::dltLast() {
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
template<class T>
void LnkdLst<T>::dltMid(Node *mid) {
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
template<class T>
void LnkdLst<T>::remove(T n) {
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

//**********************************************************
// ** function get, returns the data in the node passed in *
//**********************************************************
template<class T>
T& LnkdLst<T>::get(int n) {
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

template<class T>
void LnkdLst<T>::insertBefore(int index, T val) {
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

template<class T>
void LnkdLst<T>::insertAfter(int index, T val) {
    if (head) {
        // trying to insert out of range
        if(index>=this->size || index < 0) return;
        
        if (index==(size-1)) {append(val);}
        else {insertBefore(index+1, val);}
    }
}

//**********************************************************
// ** function extract, returns the data at index **********
// ** and deletes the node *********************************
//**********************************************************
template<class T>
T LnkdLst<T>::extract(int index) {
    if (head) {
        T temp = get(index);
        worker=head;
        Node *prev = worker;
        for(int i = 0; i != index; ++i) {
            prev = worker;
            worker=worker->next;
        }
        dltCurrent(prev);
        return temp;
    }
    return NULL;

}

template<class T>
void LnkdLst<T>::prepend(T val) {
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

template<class T>
void LnkdLst<T>::print() {
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

template<class T>
void LnkdLst<T>::sort() {
    if (head) {
        worker=head;
        Node *prev=worker;
        Node *current = prev;
        do {
            prev=worker;
            current = worker;
            while (prev=prev->next) {
                if (current->data > prev->data) {
                    T temp = current->data;
                    current->data = prev->data;
                    prev->data = temp;
                }
            }
//            current=current->next;
        } while (worker=worker->next);
    }
}

template<class T>
LnkdLst<T>& LnkdLst<T>::operator=(LnkdLst &rhs) {
    // guard against self-assignment
    if (&rhs != this) {
        Node *headLnk=new Node;
        headLnk->data=rhs.get(0);
        headLnk->next=NULL;
        head=headLnk;
        size = 1;
        rhs.worker = rhs.head;
        this->worker = this->head;
        while (rhs.worker = rhs.worker->next) {
            Node *clink = new Node;
            clink->data = rhs.worker->data;
            clink->next = NULL;
            this->worker->next = clink;
            this->worker = worker->next;
            ++size;
        }
    }
    return *this;
}