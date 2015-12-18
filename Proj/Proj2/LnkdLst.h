//
//  LnkdLst.h
//  LnkdLst
//
//  Created by Juan on 12/4/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef LnkdLst_h
#define LnkdLst_h

#include <iostream>

template <class T>
class LnkdLst {
    // forward declaration
    struct Node;
public:
    /// typedefs
    typedef Node* iterator;
    typedef const Node* const_iterator;
    
    // constructors
    LnkdLst();                  /// default constructor
    explicit LnkdLst(T);
    LnkdLst(const LnkdLst&);   /// copy constructor
    ~LnkdLst();
    
    /// iterator stuff
    iterator begin() { return head; }
    const_iterator begin() const { return head;}
    iterator end() { return NULL;}
    iterator end() const {return NULL;}
    iterator find(T) const;
    
    /// add/remove
    void append(T);
    void prepend(T);
    void insert_before(iterator, T);
    void insert_after(iterator, T);
    void remove(iterator);
    
    T get(int) const;
    T getSize() const {return size;}
    
    bool empty() const { return !head;}
    
    /// operator overloading
    LnkdLst operator=(const LnkdLst&);
    
private:
    struct Node {
        T data;
        iterator next;
    };
    
    /// data
    iterator head;
    int size;
    
    /// Utility functions
    iterator create(T);
    void destroy(iterator);
    iterator predecessor(const_iterator) const;
    
};

/// Create an empty list
template <class T>
LnkdLst<T>::LnkdLst():size(0) {
    head=NULL;
}

/// Construct a new list with an initial value
template <class T>
LnkdLst<T>::LnkdLst(T val):size(0) {
    head = create(val);
}

/// The destructor
template <class T>
LnkdLst<T>::~LnkdLst() {
    if (head) {
        iterator worker = head;
        do {
            destroy(worker);
        } while ((worker=worker->next));
    }
    size=0;
}

/// Function create creates a new node and return it
template <class T>
typename LnkdLst<T>::iterator LnkdLst<T>::create(T val) {
    iterator clink = new Node;
    clink->data = val;
    clink->next=NULL;
    ++size;
    return clink;
}

/// This function appends a node to a list
template <class T>
void LnkdLst<T>::append(T val) {
    if (head) {
        iterator worker = head;
        iterator prev = worker;
        while((worker=worker->next)) {
            prev = worker;
        }
        prev->next = create(val);
    }
    else
        head = create(val);
}

/// This function inserts a node before the head
template <class T>
void LnkdLst<T>::prepend(T val) {
    if(head)
        insert_before(head, val);
    else
        head = create(val);
}

/// This function deletes a node
template <class T>
void LnkdLst<T>::destroy(iterator node) {
    if (node){
        delete node;
        --size;
    }
}

/// This function removes a node from the list
template <class T>
void LnkdLst<T>::remove(iterator node) {
    if (node) {
        // not last in list
        if (node->next) {
            // check if head
            if (node != head){
                iterator prev = predecessor(node);
                prev->next = node->next;
                destroy(node);
            }
            else {
                head = node->next;
                destroy(node);
            }
        }
        else {
            iterator prev = predecessor(node);
            prev->next = NULL;
            destroy(node);
        }
    }
}

/// Function returns the node preceeding the the input node
template <class T>
typename LnkdLst<T>::iterator LnkdLst<T>::predecessor(const_iterator it) const{
    iterator worker = head;
    iterator prev=worker;
    do {
        prev=worker;
        worker = worker->next;
    } while (worker != it);
    
    return prev;
}

/// function returns the node containing the first instance of val
template <class T>
typename LnkdLst<T>::iterator LnkdLst<T>::find(T val) const{
    iterator out = NULL;
    iterator worker = head;
    
    do {
        if (worker->data==val) return worker;
    } while ((worker=worker->next));
    
    return out;
}

/// Insert a new node after the node specified
template <class T>
void LnkdLst<T>::insert_after(iterator it, T val) {
    if (it) {
        iterator after = create(val);
        after->next = it->next;
        it->next = after;
    }
}

/// Insert a new node before the node specified
template <class T>
void LnkdLst<T>::insert_before(iterator it, T val) {
    if (it) {
        iterator before = create(val);
        before->next = it;
        /// check if inserting before head
        if (it==head)
            head = before;
        else
            predecessor(it)->next = before;
    }
}

template <class T>
T LnkdLst<T>::get(int index) const {
        int i = 0;
        iterator worker = head;
        while (i<=index && worker) {
            ++i;
            worker=worker->next;
        }
    
    if (worker) {
        return worker->data;
    }
    return 2;
}

#endif /* LnkdLst_h */
