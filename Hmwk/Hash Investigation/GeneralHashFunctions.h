/*
 **************************************************************************
 *                                                                        *
 *          General Purpose Hash Function Algorithms Library              *
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


#ifndef INCLUDE_GENERALHASHFUNCTION_CPP_H
#define INCLUDE_GENERALHASHFUNCTION_CPP_H


#include <string>


typedef unsigned int (*HashFunction)(const std::string&);


unsigned int RSHash  (const std::string& str,int&,int&,int&,int&);
unsigned int JSHash  (const std::string& str,int&,int&,int&,int&);
unsigned int PJWHash (const std::string& str,int&,int&,int&,int&);
unsigned int ELFHash (const std::string& str,int&,int&,int&,int&);
unsigned int BKDRHash(const std::string& str,int&,int&,int&,int&);
unsigned int SDBMHash(const std::string& str,int&,int&,int&,int&);
unsigned int DJBHash (const std::string& str,int&,int&,int&,int&);
unsigned int DEKHash (const std::string& str,int&,int&,int&,int&);
unsigned int BPHash  (const std::string& str,int&,int&,int&,int&);
unsigned int FNVHash (const std::string& str,int&,int&,int&,int&);
unsigned int APHash  (const std::string& str,int&,int&,int&,int&);


#endif
