//
//  main.cpp
//  Assignment 5
//
//  Created by Juan Ruiz on 10/9/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include "LnkdLst.hpp"

void testing();
void testCopyConstructor();

int main(int argc, const char * argv[]) {
    testing();
//    testCopyConstructor();
    return 0;
}

void testing() {
    LnkdLst *lst = new LnkdLst(10);
    cout << "New list: ";
    lst->print();
    cout << "Add some nodes: ";
    lst->append(5);
    lst->append(2);
    lst->print();
    cout << "Insert 8 before 2nd node: ";
    lst->insertBefore(1, 8);
    lst->print();
    cout << "Insert 7 before head: ";
    lst->insertBefore(0, 7);
    lst->print();
    cout << "Insert 3 after head: ";
    lst->insertAfter(0, 3);
    lst->print();
    cout << "Insert after last element: ";
    lst->insertAfter(lst->getSize()-1, 9);
    cout << "Prepend 4: ";
    lst->prepend(4);
    lst->print();
    cout << "Insert 6 at end: ";
    lst->append(6);
    lst->print();
    
    cout << endl;
    cout << "First is: " << lst->first() << endl;
    cout << "Last is: " << lst->last() << endl;
    
    cout << "Use copy constructor to create a new LnkdLst, lst2: ";
    LnkdLst *lst2 = new LnkdLst(*lst);
    lst2->print();
    
    cout << "delete the original list\n";
    delete lst;
    cout << "Check to make sure that the new list still exists:  ";
    lst2->print();
    
    LnkdLst lst3(10);
    lst3.print();
    lst3 = *lst2;
    lst3.print();
    delete lst2;
    lst3.print();
    
    //newLst->print();
    //cout << newLst->getSize();
}

void testCopyConstructor() {
    cout << "Create a list";
    LnkdLst lst(0);
    for(int i = 1; i != 10; ++i) {
        lst.append(i);
    }
    cout << endl;
    LnkdLst lst2 = lst;
    cout << "lst:  ";
    lst.print();
    cout << "lst2: ";
    lst2.print();
    
    cout << "Modify the new list, leaving the old list the same: ";
    lst2.prepend(4);
    lst2.insertAfter(3, 9);
    cout << endl;
    cout << "lst:  ";
    lst.print();
    cout << "lst2: ";
    lst2.print();
    cout << lst2.getSize() << endl;
    

}