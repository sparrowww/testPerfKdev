#include "testFile2.hpp"

void CtestSize::testFunc()
{
   unsigned char byteVar = 'h';
   auto sizeVar = sizeof(byteVar);
   printf("unsigned char  size = %lu\n", sizeVar);

   unsigned short wordVar = 0xadef;
   sizeVar = sizeof(wordVar);
   printf("unsigned short size = %lu\n", sizeVar);
};


