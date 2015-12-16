//
//  BTree.hpp
//  BTree
//
//  Created by Juan on 11/21/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef BTree_hpp
#define BTree_hpp

#include<string>
#include<iostream>


class BTree {
    /// forward declaration for iterator
    struct Node;
    
public:
    typedef Node* iterator;
    
    ///****************
    ///* Constructors *
    ///****************
    BTree() {root=NULL;}
    /// constructor
    explicit BTree(int);
    
    ///****************
    ///* Destructor ***
    ///****************
    ~BTree(){destroy(root);}
    
    void insert(int);
    
    void inorder() const {inorder(root);}
    void preorder() const {preorder(root);}
    void postOrder() const {postOrder(root);}
    
    iterator begin() { return root;}
    iterator begin() const { return root;}
    
    iterator find(int);
    iterator find(int, iterator);
    
    int get(iterator it) {return it->data;}
    
    void remove(int);
    iterator minNode(iterator) const;
private:
    struct Node {
        int data;
        iterator left;
        iterator right;
    };
    
    iterator root;
    
    ///*****************************
    ///**** Utility Functions ******
    ///*****************************
    iterator create(int);
    int getData(iterator node) const {return node->data;}
    
    void insert(int, iterator);
    iterator remove(int, iterator);
    
    void destroy(iterator);
    
    void inorder(iterator) const;
    void preorder(iterator) const;
    void postOrder(iterator) const;
};

#endif /* BTree_hpp */