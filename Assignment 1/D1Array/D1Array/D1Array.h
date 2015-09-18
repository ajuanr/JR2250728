//
//  D1Array.h
//  
//
//  Created by Juan Ruiz on 9/3/15.
//
//

#ifndef ____D1Array__
#define ____D1Array__

#include <iostream>

using namespace std;

template <class T>
class D1Array {
private:
    unsigned int cols;
    T *data;
public:
    D1Array(int);
    ~D1Array();
    
    void print() const;
    T& operator[](int index) const { return data[index]; }
};

template <class T>
D1Array<T>::D1Array(int n)
:cols(n) {
    data=new T[n];
    for(int i=0;i<n;i++){
        data[i]=rand()%10+1;
        //data[i]=i+1;
    }
}

template <class T>
D1Array<T>::~D1Array() {
    delete []data;
}
template <class T>
void D1Array<T>::print() const {
    cout<<endl;
    for(int i=0;i<cols;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

#endif /* defined(____D1Array__) */
