/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/


#include <iostream>
#include <string>
#include <iomanip>
#include "GeneralHashFunctions.h"
using namespace std;

void RS(string&,string&,int, int,int,int);
void JS(string&,string&,int, int,int,int);
void ELF(string&,string&,int, int,int,int);
void BKD(string&,string&,int, int,int,int);
void SDB(string&,string&,int, int,int,int);
void DJB(string&,string&,int, int,int,int);
void DEK(string&,string&,int, int,int,int);
void FNV(string&,string&,int, int,int,int);
void BP(string&,string&,int, int,int,int);
void AP(string&,string&,int, int,int,int);

int main(int argc, char* argv[])
{
    string key = "abcdefghijklmnopqrstuvwxyz1234567890";
    string dblKey=key+key;
    int eq; // =
    int lop; // ==, <, <=, >, >=
    int lsa; // +, -, *, /
    int add; // []
    eq=lop=lsa=add=0;
    
    RS(key,dblKey,eq,lop,lsa,add);
    cout << endl;
    JS();
//   cout << " 2. JS-Hash Function Value:   " <<setw(15)<< JSHash(key,eq,lop,lsa,add)   <<endl;
//   cout << " 3. PJW-Hash Function Value:  " <<setw(15)<< PJWHash(key,eq,lop,lsa,add)  <<endl;
//   cout << " 4. ELF-Hash Function Value:  " <<setw(15)<< ELFHash(key,eq,lop,lsa,add)  <<endl;
//   cout << " 5. BKDR-Hash Function Value: " <<setw(15)<< BKDRHash(key,eq,lop,lsa,add) <<endl;
//   cout << " 6. SDBM-Hash Function Value: " <<setw(15)<< SDBMHash(key,eq,lop,lsa,add) <<endl;
//   cout << " 7. DJB-Hash Function Value:  " <<setw(15)<< DJBHash(key,eq,lop,lsa,add)  <<endl;
//   cout << " 8. DEK-Hash Function Value:  " <<setw(15)<< DEKHash(key,eq,lop,lsa,add)  <<endl;
//   cout << " 9. FNV-Hash Function Value:  " <<setw(15)<< FNVHash(key,eq,lop,lsa,add)  <<endl;
//   cout << "10. BP-Hash Function Value:   " <<setw(15)<< BPHash(key,eq,lop,lsa,add)   <<endl;
//   cout << "11. AP-Hash Function Value:   " <<setw(15)<< APHash(key,eq,lop,lsa,add)   <<endl;

   return true;
}

void RS(string& key, string& dblKey, int eq, int lop, int lsa, int add) {
    cout << "Key:     " <<key<<endl;
    cout << " 1. RS-Hash Function Value:   " <<setw(15)<< RSHash(key,eq,lop,lsa,add)   <<endl;
    cout << "     Operations: " <<  eq+lop+lsa+add << endl;
    cout << dblKey << endl;
    cout << " 1. RS-Hash Function Value:   " <<setw(15)<< RSHash(dblKey,eq,lop,lsa,add)   <<endl;
    cout << "     Doubled size, # operations: " <<  eq+lop+lsa+add << endl;
}

void JS(string& key, string& dblKey, int eq, int lop, int lsa, int add) {
    string key = "abcdefghijklmnopqrstuvwxyz1234567890";
    string dblKey=key+key;
    int eq; // =
    int lop; // ==, <, <=, >, >=
    int lsa; // +, -, *, /
    int add; // []
    eq=lop=lsa=add=0;
    
    cout << "Key:     " <<key<<endl;
    cout << " 1. RS-Hash Function Value:   " <<setw(15)<< JSHash(key,eq,lop,lsa,add)   <<endl;
    cout << "     Operations: " <<  eq+lop+lsa+add << endl;
    cout << dblKey << endl;
    cout << " 1. RS-Hash Function Value:   " <<setw(15)<< JSHash(dblKey,eq,lop,lsa,add)   <<endl;
    cout << "     Doubled size, # operations: " <<  eq+lop+lsa+add << endl;
}