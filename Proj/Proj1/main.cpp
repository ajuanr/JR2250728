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
    area->print();
    return 0;
}
