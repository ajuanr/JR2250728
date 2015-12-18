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
    
    return node;
}

///// function prints the tree in sorted order
//void BTree::inorder() {
//    inorder(root);
//}

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

/// add a val to the tree, attached to the 'node'
void BTree::insert(int val, iterator node) {
    if (node) {
        /// val < root goes on left
        if(val < node->data) {
            /// check if node exists
            if (node->left==NULL) {
                node->left = create(val);
                return;
            }
            insert(val, node->left);
        }
        /// data was greater than root, put on right
        else {
            /// check if node exists
            if(node->right==NULL) {
                node->right = create(val);
                return;
            }
            insert(val, node->right);
        }
    }
}

BTree::iterator BTree::find(int val) {
    return find(val, root);
}

BTree::iterator BTree::find(int val, iterator node) {
    if (node) {
        if (node->data==val) {
            return node;
        }
        find(val,node->left);
        find(val,node->right);
    }
    return node;
}

void BTree::remove(int val) {
    remove(val, root);
}

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
