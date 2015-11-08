//
//  main.cpp
//  Project
//
//  Created by Juan Ruiz on 11/7/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

// system libraries
#include <iostream>

// user libraries
#include "Grid.hpp"

int main(int argc, const char * argv[]) {
    Grid *area = new Grid();
    area->init();
    std::cout << endl;
    area->prntClr();
    delete area;
    return 0;
}
