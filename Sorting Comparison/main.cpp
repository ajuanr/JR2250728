#include <iostream>
#include <cmath>
using namespace std;

void quickSort(int [], int, int,int&,int&,int&,int&);
int pivot(int [], int, int,int&,int&,int&,int&);
void swap(int&, int&,int&,int&,int&,int&);
void print(int [], const int&);
void merge(int*,int,const int, const int,int&,int&,int&,int&);
void merge_sort(int*, const int, const int,int&,int&,int&,int&);
void heapsort(int [], int);
void buildheap(int [], int);
void heapify(int [], int, int);

void filAray(int [],int);

void quicksortAnalysis();
void mergesortAnalysis();
int main(){
    //int test[] = { 7, -13, 1, 3, 10, 5, 2, 4 };
    //int N = sizeof(test)/sizeof(int);
    
    int SIZE = 800;
    int DBLSIZE=SIZE*2;
    
    int test[SIZE];
    filAray(test, SIZE);
    
    int test2[DBLSIZE];
    filAray(test2, DBLSIZE);
    
    cout << "quicksort Analysis: " << endl;
    quicksortAnalysis();
    cout << endl;
    cout << "Merge sort analysis" << endl;
    mergesortAnalysis();
//    cout << "Size of test array :"  << SIZE << endl;
    
//    cout << "Before sorting : " << endl;
//    print(test, SIZE);
    int eq; // =
    int lop; // ==, <, <=, >, >=
    int lsa; // +, -, *, /
    int add; // []
    eq=lop=lsa=add=0;
    //quickSort(test, 0, SIZE-1, eq,lop,lsa,add);
    //merge_sort(test, 0, N-1);
    //heapsort(test, N);
    
//    cout << endl << endl << "After sorting : " << endl;
//    print(test, SIZE);
    
    //cout<<"Size of the array to sort = "<<SIZE<<endl;
//    cout<<"Total number of equalities = "<<eq<<endl;
//    cout<<"Total number of logical operations = "<<lop<<endl;
//    cout<<"Total number of add/sub operations = "<<lsa<<endl;
//    cout<<"Total number of addressing operations = "<<add<<endl;
    //cout<<"Total number of operations = "<<eq+lop+lsa+add<<endl;
    
    
    eq=lop=lsa=add=0;
    quickSort(test2, 0, DBLSIZE-1, eq,lop,lsa,add);
    //merge_sort(test, 0, N-1);
    //heapsort(test, N);
    
//    cout<<"Size of the array to sort = "<<SIZE<<endl;
//  cout<<"Total number of equalities = "<<eq<<endl;
//  cout<<"Total number of logical operations = "<<lop<<endl;
//  cout<<"Total number of add/sub operations = "<<lsa<<endl;
//  cout<<"Total number of addressing operations = "<<add<<endl;
//    cout<<"Total number of operations = "<<eq+lop+lsa+add<<endl;
    
    return 0;
}

/**
 * Quicksort.
 * @param a - The array to be sorted.
 * @param first - The start of the sequence to be sorted.
 * @param last - The end of the sequence to be sorted.
 */
void quickSort(int a[], int first, int last,int &eq, int &lop, int &lsa, int &add) {
    int pivotElement;
    ++lop;
    if(first < last)
    {
        ++eq; lsa+=2;
        pivotElement = pivot(a, first, last,eq,lop,lsa,add);
        quickSort(a, first, pivotElement-1, eq,lop,lsa,add);
        quickSort(a, pivotElement+1, last, eq,lop,lsa,add);
    }
}

/**
 * Find and return the index of pivot element.
 * @param a - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
 * @return - the pivot element
 */
int pivot(int a[], int first, int last,int &eq, int &lop, int &lsa, int &add) {
    eq+=2;
    ++add;
    int  p = first;
    int pivotElement = a[first];
    ++eq; ++lsa;
    for(int i = first+1 ; i <= last ; i++)
    {
        lop+=2; ++lsa;
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement)
        {
            ++lsa; add+=2;
            p++;
            swap(a[i], a[p]);
        }
    }
    add+=2;
    swap(a[p], a[first]);
    
    return p;
}


/**
 * Swap the parameters.
 * @param a - The first parameter.
 * @param b - The second parameter.
 */
void swap(int& a, int& b,int &eq, int &lop, int &lsa, int &add){
    eq+=3;
    int temp = a;
    a = b;
    b = temp;
}

/**
 * Print an array.
 * @param a - The array.
 * @param N - The size of the array.
 */
void print(int a[], const int& N){
    for(int i = 0 ; i < N ; i++)
        cout << "array[" << i << "] = " << a[i] << endl;
}

void merge(int* A,int p,const int q, const int r,
           int &eq, int &lop, int &lsa, int &add){
    eq+=7; lsa+=4; add+=4;
    const int n_1=q-p+1;
    const int n_2=r-q;
    int* L = new int [n_1+1];
    int* R = new int [n_2+1];
    L[n_1]=0;
    R[n_2]=0;
    for(int i = 0; i < n_1; i++){
        lop++; eq++; add+=2; lsa+=2;
        L[i] = A[p+i];
    }
    eq++;
    for (int j = 0; j < n_2; j++) {
        lop+=2; lsa+=3; add+=2;
        R[j] = A[q+j+1];
    }
    
    eq+=2;
    int i=0;
    int j=0;

    int k;
    eq++;
    for(k=p; k <= r && i < n_1 && j < n_2; ++k)
    {
        lop+=4; lsa++; add+=2;
        if(L[i] <= R[j])
        {
            add+=2; eq++; lsa++;
            A[k] = L[i];
            i++;
        }
        else
        {
            add+=2; eq++; lsa++;
            A[k] = R[j];
            j++;
        }
    }
    // Added the following two loop.
    // Note only zero or one loop will actually activate.
    lop++;
    while (i < n_1) {add+=2; lsa+=2; eq++; A[k++] = L[i++];}
    lop++;
    while (j < n_2) {add+=2; lsa+=2; eq++; A[k++] = R[j++];}
}

void merge_sort(int* A, const int p, const int r,int &eq, int &lop, int &lsa, int &add){
    lop++;
    if (p < r)
    {
        eq++; lsa+=2;
        int q = (p+r)/2;
        merge_sort(A, p,q, eq,lop,lsa,add);
        merge_sort(A,q+1,r, eq,lop,lsa,add);
        merge(A,p,q,r, eq,lop,lsa,add);
    }
}

void heapsort(int A[], int length)//	       (takes O(n lg n) time)
{
    int heapsize = length;
    
    buildheap(A, length);	//Take the unsorted list and make it a heap
    for (int i = length-1; i >=1; i--)
    {
        swap(A[0], A[i]);
        heapsize--;
        heapify(A, heapsize, 0);
    }
}

void buildheap(int A[], int length)	//     (takes O(n) time)
{
    for (int i = floor((length)/2); i >= 0 ; i--)
        heapify(A, length, i);
}

void heapify(int A[], int heapsize, int root) //(takes O(h) h is the height of root
{
    int left = 2*root+1,
    right = 2*root +2,
    largest;
    
    if ( (left < heapsize) && (A[left] > A[root]))
        largest = left;
    else
        largest = root;
    
    if ( (right < heapsize) && (A[right] > A[largest]))
        largest = right;
    
    if (largest != root)
    {
        swap(A[root], A[largest]);
        heapify(A, heapsize, largest);
    }
}

void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
}

void quicksortAnalysis() {
    int SIZE = 800;
    int DBLSIZE=SIZE*2;
    
    int test[SIZE];
    filAray(test, SIZE);

    int eq; // =
    int lop; // ==, <, <=, >, >=
    int lsa; // +, -, *, /
    int add; // []
    eq=lop=lsa=add=0;
    quickSort(test, 0, SIZE-1, eq,lop,lsa,add);
    
    cout<<"Size of the array to sort = "<<SIZE<<endl;
    int total1=eq+lop+lsa+add;
    cout<<"Total number of operations = "<<total1 <<endl;
    
    int test2[DBLSIZE];
    filAray(test2, DBLSIZE);
    eq=lop=lsa=add=0;
    
    quickSort(test2, 0, DBLSIZE-1, eq,lop,lsa,add);
    int total2=eq+lop+lsa+add;
    cout<<"Size of the array to sort = "<<SIZE<<endl;
    cout<<"Total number of operations = "<<total2 << endl;
    
    cout << "Ratio of operations:     " << total2/1.0/total1 << endl;
    cout << "Ratio of logs (nlog(n)): " << (DBLSIZE*log2(DBLSIZE))/(SIZE*log2(SIZE))
         << endl;
}

void mergesortAnalysis() {
    int SIZE = 800;
    int DBLSIZE=SIZE*2;
    
    int test[SIZE];
    filAray(test, SIZE);
//        cout << "Before sorting : " << endl;
//        print(test, SIZE);
    
    int eq; // =
    int lop; // ==, <, <=, >, >=
    int lsa; // +, -, *, /
    int add; // []
    eq=lop=lsa=add=0;
    merge_sort(test, 0, SIZE-1, eq,lop,lsa,add);
    
//    cout << "After sorting : " << endl;
//    print(test, SIZE);
    
    cout<<"Size of the array to sort = "<<SIZE<<endl;
    int total1=eq+lop+lsa+add;
    cout<<"Total number of operations = "<<total1 <<endl;
    
    int test2[DBLSIZE];
    filAray(test2, DBLSIZE);
    eq=lop=lsa=add=0;
    
    merge_sort(test2, 0, DBLSIZE-1, eq,lop,lsa,add);
    int total2=eq+lop+lsa+add;
    cout<<"Size of the array to sort = "<<SIZE<<endl;
    cout<<"Total number of operations = "<<total2 << endl;
    
    cout << "Ratio of operations:     " << total2/1.0/total1 << endl;
    cout << "Ratio of logs (nlog(n)): " << (DBLSIZE*log2(DBLSIZE))/(SIZE*log2(SIZE))
    << endl;
}