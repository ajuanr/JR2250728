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
#include <numeric>

using namespace std;

void fill(vector<int>&, int, int = 9);
void printArray(vector<int>&, int=100);
void mode(const vector<int>&);
int max(const map<int,int>);

int main(int argc, const char * argv[]) {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    vector<int> v;
    // number for random number generator
    cout << "What is the largest value to use: ";
    int mod;
    cin >> mod;
        
    // numbers to print per line
    cout << "How many numbers to print per line: ";
    int perLine;
    cin >> perLine;
    
    fill(v, size, mod);
    
    printArray(v, perLine);
    
    if (!v.empty()) {
        // sort the array to get the mode, original vector will be lost
        sort(v.begin(), v.end());
        printArray(v, perLine);
        cout<<"Mean: "<<accumulate(v.begin(), v.end(), 0.0) / v.size()
             << endl;
        cout << "Median: " << ((size%2==0) ? v[size/2]: v[size/2+1]);
    mode(v);
    }
    else
        cout << "No data was input\n";

    return 0;
}


void fill(vector<int>& a, int size, int mod) {
    // use current time as seed for random number generator
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i != size; ++i) {
        a.push_back(i%mod+1);//rand() % mod + 1);
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

void mode(const vector<int>& v) {
    set<int> s(v.begin(), v.end());
    
    cout << "\nNumbers in set:\n";
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    map<int, int> m;
    
    typedef set<int>::iterator setIt;
    typedef map<int, int>::iterator mapIt;
    
    // add the keys to the map
    for(setIt it = s.begin(); it != s.end(); ++it) {
        m[*it];//.insert({*it, 0});
    }
    
    // add the values to the keys
    for (vector<int>::const_iterator it=v.begin(); it != v.end(); ++it) {
        ++m[*it];
    }
    cout << endl;
    
    for (mapIt it=m.begin(); it != m.end(); ++it) {
        cout << "key: " << it->first << " value: " << it->second << " ";
    }
    cout << endl;
    int maxVal = max(m);
    cout << maxVal << endl;
    // if max is 1, then no number is repeated
    if (maxVal==1) {
        cout << "Mode: {0}";
    }
    
    else {
        cout << "Mode: { ";
        for (mapIt it = m.begin(); it != m.end(); ++it) {
            if (it->second == maxVal) {
                cout << it->first << " ";
            }
        }
        cout << "}\n";
    }
    cout << endl;
}
int max(const map<int,int> m) {
    int max = m.begin()->second;
    for (map<int, int>::const_iterator it= m.begin(); it!= m.end(); ++it) {
        if (it->second > max) {
            max = it->second;
        }
    }
    return max;
}