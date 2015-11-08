//
//  SimpleVector.h
//  SimpleVector
//
//  Created by Juan Ruiz on 9/16/15.
//  Copyright (c) 2015 Juan Ruiz. All rights reserved.
//

#ifndef SimpleVector_SimpleVector_h
#define SimpleVector_SimpleVector_h

//SimpleVector Class Template

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    
    // Default constructor
    SimpleVector()
    { aPtr = 0; arraySize = 0; avail=0;}
    
    // Constructor declaration
    SimpleVector(int);
    
    // Copy constructor declaration
    SimpleVector(const SimpleVector &);
    
    // Destructor declaration
    ~SimpleVector();
    
    // Accessor to return the array size
    int size() const
    { return avail; } // changed from arraySize
    
    // Accessor to return a specific element
    T getElementAt(int position);
    
    // Overloaded [] operator declaration
    T &operator[](const int &);
    T &operator[](const int &) const;
    
    // Pushes new element onto array
    void push_back(T);
    
    // Remove an element from array
    T pop();
    
    // return true if array if empty
    bool empty() const {return !aPtr;}
    
    iterator begin() {return aPtr;}
    const_iterator begin() const {return aPtr;}
    iterator end() {return aPtr+avail;}
    const_iterator end() const {return aPtr+avail;}
    
    void print() const;
private:
    iterator aPtr;          // To point to the allocated array
    int avail;        // points to one past last element pushed
    int arraySize;    // Total number of elements in the array
    void memError();  // Handles memory allocation errors
    void subError() const;  // Handles subscripts out of range
    
    void create(int); // create a SimpleVector
    void expand();    // double the size of the SimpleVector
    
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s){ create(s); }

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // Copy the array size.
    arraySize = obj.arraySize;
    avail = obj.avail; // added by me
    
    // Allocate memory for the array.
    aPtr = new T [arraySize];
    if (aPtr == 0)
        memError();
    
    // Copy the elements of obj's array.
    for(int count = 0; count < arraySize; count++)
        *(aPtr + count) = *(obj.aPtr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete [] aPtr;
}

//************************
// Create a SimpleVector *
//************************

template<class T>
void SimpleVector<T>::create(int s) {
    arraySize = s;
    avail = 0; // added by me
    // Allocate memory for the array.
    try
    {
        aPtr = new T [s];
    }
    catch (bad_alloc)
    {
        memError();
    }
    
    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
        *(aPtr + count) = 0;
}

//*************************************************
// expand Function. Doubles the size of the array *
//*************************************************

template<class T>
void SimpleVector<T>::expand() {
    // temporary SimpleArray that holds a copy of the original array
    SimpleVector<T> temp = *this;
    
    create(temp.size()*2); // create a new array with double the size
    
    // copy the elements over
    for (int i = 0; i != temp.size(); ++i)
        *(aPtr + i) = temp[i];
    
    // move the avail index back to original position
    avail = temp.size();
}

//*******************************************************
// push Function. add a new element to end of array     *
// double the size of array if size of array is reached *
//*******************************************************

template <class T>
void SimpleVector<T>::push_back(T n) {
    // vector has not been initialized yet
    if(empty()) create(10);
    
    // check you're not past the last element
    if (avail == arraySize) expand();
    
    // push the new element
    *(aPtr+avail) = n;
    ++avail;
}

//*****************************************
// pop Function. Remove the last element *
//*****************************************

template <class T>
T SimpleVector<T>::pop() {
    --avail;
    
    // attempting to pop from empty array
    if (avail < 0)
        subError();

    // elements available to pop
    T popped = *(aPtr+avail);
    return popped;
}

//***************************************************************
// print Funtion. Print elements until the last pushed element  *
//***************************************************************

template <class T>
void SimpleVector<T>::print() const {
    for (int i = 0; i != avail; ++i) {
        cout << *(aPtr+i) << " ";
    }
    cout << endl;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError() const
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aPtr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aPtr[sub];
}

template <class T>
T &SimpleVector<T>::operator[](const int &sub) const
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aPtr[sub];
}

#endif
