//
//  main.cpp
//  Assignment 5
//
//  Created by Juan Ruiz on 10/9/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include "LnkdLst.hpp"

int main(int argc, const char * argv[]) {
    LnkdLst *lst = new LnkdLst(10);
    
    lst->append(5);
    lst->append(2);
    lst->insertBefore(1, 8);
    lst->insertBefore(3, 7);
    lst->insertAfter(4, 3);
    for(int i =0; i != lst->getSize(); ++i) {
        cout << lst->get(i) << " ";
    }
    cout << endl;
    cout << "First is: " << lst->first() << endl;
    cout << "Last is: " << lst->last() << endl;

    return 0;
}
