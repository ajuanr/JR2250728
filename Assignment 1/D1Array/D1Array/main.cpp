//
//  main.cpp
//  D1Array
//
//  Created by Juan Ruiz on 9/3/15.
//  Copyright (c) 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

// user libraries
#include "D2Array.h"


int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    
//    D2Array<int> *array = new D2Array<int>(10);
   D2Array<float> *array = new D2Array<float>(10);
    
    array->print();

    delete array;
    
    return 0;
}
