//
//  main.cpp
//  Assignment 7
//
//  Created by Juan Ruiz on 10/22/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void fill(vector<int>&, int, int = 9);
void printArray(vector<int>&, int=100);

int main(int argc, const char * argv[]) {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    vector<int> a;
    // number for random number generator
    cout << "What is the largest value to use: ";
    int mod;
    cin >> mod;
        
    // numbers to print per line
    cout << "How many numbers to print per line: ";
    int perLine;
    cin >> perLine;
    
    fill(a, size, mod);
    
    printArray(a, perLine);
    
    set<int> s(a.begin(), a.end());
    
    cout << "\nNumbers in set:\n";
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    map<int, int> m;
    
    typedef set<int>::iterator setIt;
    typedef map<int, int>::iterator mapIt;
    
    for(setIt it = s.begin(); it != s.end(); ++it) {
        m.insert({*it, 0});
    }
    
    for (vector<int>::const_iterator it=a.begin(); it != a.end(); ++it) {
        m[*it]++;
    }
    
    for (mapIt it=m.begin(); it != m.end(); ++it) {
        cout << " key: " << it->first << " value: " << it->second;
    }
    cout << endl;
    cout << "max is: " << max_element(m.begin(), m.end())->first;
    
    cout << endl;
    return 0;
}


void fill(vector<int>& a, int size, int mod) {
    // use current time as seed for random number generator
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i != size; ++i) {
        a.push_back(rand() % mod + 1);
    }
}

void printArray(vector<int>& a, int p) {
    for (int i = 0; i != a.size(); ++i) {
        cout << a[i] << " ";
        if (i % p == p-1)
            cout << endl;
    }
    cout << endl;
}
