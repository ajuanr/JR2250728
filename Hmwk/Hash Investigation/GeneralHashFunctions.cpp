#include "GeneralHashFunctions.h"

unsigned int RSHash(const std::string& str,
                    int &eq, int &lop, int &lsa, int &add)
{
    eq=lop=lsa=add=0;
    
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;
    eq+=4;
    
   for(std::size_t i = 0; i < str.length(); i++)
   {
       
      hash = hash * a + str[i];
      a    = a * b;
       eq+=2;
       lsa+=4;
       add+=1;
       lop++;
   }

   return hash;
}
/* End Of RS Hash Function */


unsigned int JSHash(const std::string& str,
                    int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
    
   unsigned int hash = 1315423911;
    eq+=2;
   for(std::size_t i = 0; i < str.length(); i++)
   {
       eq++;
       lsa+=4;
       add++;
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash;
}
/* End Of JS Hash Function */


unsigned int PJWHash(const std::string& str,
                     int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
    
   unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;

    eq+=7;
   for(std::size_t i = 0; i < str.length(); i++)
   {
       eq++;
       lsa++;
       add++;
      hash = (hash << OneEighth) + str[i];

       eq++;
       lop++;
      if((test = hash & HighBits)  != 0)
      {
          eq++;
          lop++;
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}
/* End Of  P. J. Weinberger Hash Function */


unsigned int ELFHash(const std::string& str,
                     int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
    
   unsigned int hash = 0;
   unsigned int x    = 0;
    eq+=3;
    
   for(std::size_t i = 0; i < str.length(); i++)
   {
       eq+=2;
       add++;
      hash = (hash << 4) + str[i];
       lop++;
      if((x = hash & 0xF0000000L) != 0)
      {
          eq++;
          lop++;
         hash ^= (x >> 24);
      }
       eq++;
      hash &= ~x;
   }

   return hash;
}
/* End Of ELF Hash Function */


unsigned int BKDRHash(const std::string& str,
                      int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
    
   unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
   unsigned int hash = 0;

    eq+=3;
   for(std::size_t i = 0; i < str.length(); i++)
   {
       add++;
       eq++;
       lsa+=2;
       lop++;
      hash = (hash * seed) + str[i];
   }

   return hash;
}
/* End Of BKDR Hash Function */


unsigned int SDBMHash(const std::string& str,
                      int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
    
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = str[i] + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}
/* End Of SDBM Hash Function */


unsigned int DJBHash(const std::string& str,
                     int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
    
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return hash;
}
/* End Of DJB Hash Function */


unsigned int DEKHash(const std::string& str,
                     int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
    
   unsigned int hash = static_cast<unsigned int>(str.length());

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
   }

   return hash;
}
/* End Of DEK Hash Function */


unsigned int BPHash(const std::string& str,
                    int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash << 7 ^ str[i];
   }

   return hash;
}
/* End Of BP Hash Function */


unsigned int FNVHash(const std::string& str,
                     int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash *= fnv_prime;
      hash ^= str[i];
   }

   return hash;
}
/* End Of FNV Hash Function */


unsigned int APHash(const std::string& str,
                    int &eq, int &lop, int &lsa, int &add)
{
        eq=lop=lsa=add=0;
   unsigned int hash = 0xAAAAAAAA;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ str[i] * (hash >> 3)) :
                               (~((hash << 11) + (str[i] ^ (hash >> 5))));
   }

   return hash;
}
/* End Of AP Hash Function */
