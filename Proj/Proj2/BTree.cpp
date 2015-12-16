//
//  BTree.cpp
//  BTree
//
//  Created by Juan on 11/21/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include <iostream>

#include "BTree.hpp"

using namespace std;

BTree::BTree(int val) {
    root = create(val);
}

/// Functions creates a node in the tree
BTree::iterator BTree::create(int val) {
    iterator node = new Node;
    node->data = val;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    
    return node;
}


/// function prints the tree starting at a certain node
void BTree::inorder(iterator node) const {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void BTree::preorder(iterator node) const {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BTree::postOrder(iterator node) const {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

/// function destroy deletes the entire tree
void BTree::destroy(iterator node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

/// function inserts a value into the tree
void BTree::insert(int val) {
    if (root) {
        insert(val, root);
    }
    else {
        root = create(val);
    }
}

BTree::iterator BTree::insert(int val, iterator node)
{
    if (node == NULL)
        return (create(val));
    
    if (val < node->data)
        node->left  = insert(val, node->left);
    else
        node->right = insert(val, node->right);
    
    node->height = max(height(node->left), height(node->right)) + 1;
    
    int bal = balance(node);
    
    // If this node becomes unbalanced, then there are 4 cases
    
    // Left Left Case
    if (bal > 1 && val < node->left->data)
        return rightRotate(node);
    
    // Right Right Case
    if (bal < -1 && val > node->right->data)
        return leftRotate(node);
    
    // Left Right Case
    if (bal > 1 && val > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left Case
    if (bal < -1 && val < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    /* return the (unchanged) node pointer */
    return node;
}

BTree::iterator BTree::find(int val) {
    return find(val, root);
}

BTree::iterator BTree::find(int val, iterator node) {
    if (node) {
        if (node->data==val) {
            cout << "Found val: " << val << endl;
            return node;
        }
        find(val,node->left);
        find(val,node->right);
    }
    return node;
}

/// this function removes a value from the tree
void BTree::remove(int val) {
    remove(val, root);
}


/// this function removes a value from the tree
BTree::iterator BTree::remove(int val, iterator node) {
    if (node == NULL) {
        return node;
    }
    else if (val <node->data) {
        node->left = remove(val, node->left);
    }
    else if (val > node->data) {
        node->right = remove(val, node->right);
    }
    else {
        // node has no children
        if (node->left == NULL && node->right == NULL) {
            delete node;
            node = NULL;
            return node;
        }
        // only has one child
        else if (node->left == NULL) {
            iterator temp = node;
            node = node->right;
            delete temp;
            return node;
        }
        else if (node->right == NULL) {
            iterator temp = node;
            node = node->left;
            delete temp;
            return node;
        }
        // two children
        else {
            iterator temp = minNode(node->right);
            node->data = temp->data;
            node->right = remove(temp->data, node->right);
        }
    }
    return node;
}

/// this function returns the minimum value
BTree::iterator BTree::minNode(iterator node) const {
    if (node->left == NULL)
        return node;
    else
        return minNode(node->left);
}


int BTree::height(iterator node) const {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}


///*****************************
///******* AVL Stuff ***********
///*****************************
BTree::iterator BTree::rightRotate(iterator pivot) {
    iterator x = pivot->left;
    iterator T2 = x->right;
    
    // Perform rotation
    x->right = pivot;
    pivot->left = T2;
    
    // Update heights
    pivot->height = max(height(pivot->left), height(pivot->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    
    // Return new root
    return x;
}

BTree::iterator BTree::leftRotate(iterator pivot) {
    iterator y = pivot->right;
    iterator T2 = y->left;
    
    // Perform rotation
    y->left = pivot;
    pivot->right = T2;
    
    //  Update heights
    pivot->height = max(height(pivot->left), height(pivot->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    
    // Return new root
    return y;
}

int BTree::balance(iterator node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
