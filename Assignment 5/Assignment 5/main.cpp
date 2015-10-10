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

int main(int argc, const char * argv[]) {
    testing();

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
    
    delete lst;
}
