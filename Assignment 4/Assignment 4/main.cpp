//
//  main.cpp
//  Assignment 4
//
//  Created by Juan Ruiz on 10/1/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>

// user libraries
#include "LnkdLst.hpp"

int main(int argc, const char * argv[]) {
    LnkdLst vl(5);
    cout << vl.getSize() << endl;
    vl.append(7);
    vl.append(9);
    vl.append(4);
    cout << vl.getSize() << endl;
    vl.dltLast();
    cout << vl.toString();
    cout << vl.getElementAt(2) << endl;
    cout << vl[1] << endl;
    return 0;
}
