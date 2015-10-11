//
//  main.cpp
//  Assignment 5
//
//  Created by Juan Ruiz on 10/9/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

// system libraries
#include <iostream>
#include <string>

using namespace std;

// user libraries
#include "LnkdLst.hpp"

void testing();
void testTemplate();

int main(int argc, const char * argv[]) {
    testing();
    testTemplate();

    return 0;
}

void testing() {
    LnkdLst<int> *lst = new LnkdLst<int>(10);
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
    cout << "Insert 9 after last element: ";
    lst->insertAfter(lst->getSize()-1, 9);
    lst->print();
    cout << "Remove the second element: ";
    lst->extract(2);
    lst->print();
    cout << "Prepend 4: ";
    lst->prepend(4);
    lst->print();
    cout << "Append 6: ";
    lst->append(6);
    lst->print();
    
    cout << endl;
    cout << "First is: " << lst->first() << endl;
    cout << "Last is: " << lst->last() << endl;
    cout << endl;
    
    cout << "Use copy constructor to create a new LnkdLst, lst2: ";
    LnkdLst<int> *lst2 = new LnkdLst<int>(*lst);
    lst2->print();
    
    cout << "delete the original list\n";
    delete lst;
    cout << "Check to make sure that the new list still exists:  ";
    lst2->print();
    
    cout << "\nCreate a new list to test assignment operator: ";
    LnkdLst<int> lst3(10);
    lst3.print();
    cout << "Assign lst2 to lst3: ";
    lst3 = *lst2;
    lst3.print();
    cout << "Make sure self-assignemt works: ";
    LnkdLst<int> *lst3Ptr = &lst3;
    lst3 = *lst3Ptr;
    lst3.print();
    delete lst2;
    cout << "Deleting lst2\n";
    lst3.print();
}

void testTemplate() {
    cout << "\nTest templated lnkLst: ";
    LnkdLst<string> *lst = new LnkdLst<string>("this");
    lst->print();
    cout << "Append to list: ";
    lst->append("working");
    lst->print();
    cout << "test insertBefore(): ";
    lst->insertBefore(1, "is");
    lst->print();
    cout << "Prepend a node: ";
    lst->prepend("not");
    lst->print();
    cout << "Extract the prepended node: " << endl;
    cout << "Extracted node is: " << lst->extract(0) << endl;
    lst->print();
}
