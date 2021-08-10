#include "testFile2.hpp"

void CtestSize::testFunc()
{
   unsigned char byteVar = 'h';
   unsigned sizeVar = sizeof(byteVar);
   printf("unsigned char  size = %d\n", sizeVar);

   unsigned short byte2Var = 0xadef;
   sizeVar = sizeof(byte2Var);
   printf("unsigned short size = %d\n", sizeVar);

   unsigned int byte4Var = 0;
   sizeVar = sizeof(byte4Var);
   printf("unsigned int size = %d\n", sizeVar);

   unsigned long byte8Var = 0;
   sizeVar = sizeof(byte8Var);
   printf("unsigned long size = %d\n", sizeVar);

   float floatVar = 0;
   sizeVar = sizeof(floatVar);
   printf("float size = %d\n", sizeVar);

   double doubleVar = 0;
   sizeVar = sizeof(doubleVar);
   printf("double size = %d\n", sizeVar);

   MyStruct myStruct;
   sizeVar = sizeof(myStruct);
   printf("MyStruct size = %d\n", sizeVar);
   printf("MyStruct.size() = %d\n", myStruct.size());
   printf("MyStruct char1[%d], char2[%d], char3[%d], char4[%d]\n", myStruct.char1, myStruct.char2, myStruct.char3, myStruct.char4);
   myStruct.char1 = 42;
   MyStruct myStruct2;
   myStruct2 = myStruct;
   printf("myStruct2.char1 = %d\n", myStruct2.char1);

   CSizeCheck sizeCheck;
   sizeVar = sizeof(sizeCheck);
   printf("CSizeCheck size = %d\n", sizeVar);
   printf("CSizeCheck var1 = %d\n", sizeCheck.getVar1());
};



