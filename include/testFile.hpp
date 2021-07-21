#ifndef TESTFILE_HPP
#define TESTFILE_HPP

#include <iostream>
#include <unistd.h>
using namespace std;
#include <algorithm>
#include "vector"
#include "list"
#include <memory>

#include <chrono>
#include <ctime>
#include <ratio>
using namespace chrono;

#include "ccout.hpp"

class TESTCLASS
{
   public:
      TESTCLASS();
      ~TESTCLASS();
      void stringAddTest ();
      void intAddTest ();
      void postIncrementTest ( unsigned numInc );
      void postIncrementTestWhile ( unsigned numInc );
      void preIncrementTest ( unsigned numInc );
      void preIncrementTestWhile ( unsigned numInc );
      void testStringCopy ();
      void testParentChild();
      void testBinarySearch();
      void testBinarySearchNum( int num );
      void testMyType();
      void testUniqueCleverPointer ();
      void testUniqueCleverPointer2 ();
      void testSharedCleverPointer ();
      void testMyCleverPointer ();
      void testBiteStruct();
   private:
      inline void startChronoTime ();
      inline void stopChronoTime ( string &text );

      void colorCOUT ( string text, short color, bool flEndl );
      void colorCOUT2 ( string &text, short color, bool flEndl );

      high_resolution_clock::time_point difft1; ///< начальное время при запуске таймера
      high_resolution_clock::time_point difft2; ///< конечное время при остановке таймера
      duration<double, milli> time_span;
      string textToPrint;
      time_t seconds;
      struct tm *timeinfo;
      char nowdate[255];
      CCOUT * ccout;
};

class A
{
   public:
      A (){cout << "A()" << endl; num = 0;};
      virtual ~A (){cout << "~A() = "<< num << endl;};
      virtual void changeNumber () { num += 2;};
   protected:
      unsigned num;
};

class B : public A
{
   public:
      B () {cout << "B()" << endl;};
      virtual ~B () {cout << "~B() = "<< num << endl;};
      virtual void changeNumber () { num += 9;};
};

class myClass
{
   public:
      myClass(){a = 0;};
      ~myClass(){};
      myClass(const myClass & mCl){a = mCl.a;};
      myClass & operator = (const myClass & mCl) {a = mCl.a;};
      bool operator < (const myClass & mCl) {return (a < mCl.a);};
      void printAEndl ( const string & text = "") {cout <<text << ", a = "<< a << endl;};
      void printA () {cout << "|"<< a;};
      void setA( const int setA ){ a = setA;};
   private:
      int a;

};

class myPointers
{
   public:
      myPointers():var(0)
      {
         cout <<"myPointers()"<<endl;
      };
      ~myPointers()
      {
         cout <<"~myPointers()"<<endl;
      };
      myPointers * getInstance () {return this;};
      void setVar (int _var){var= _var;};
      int getVar (){return var;};
      void printVar (){printf("printVar(%d)\n", var);};
   private:
      int var;
};

template <typename T>
class myClPtr
{
   public:
      myClPtr(T * workPtr = nullptr):var(workPtr){};
      ~myClPtr()
      {
         delete var;
         var=nullptr;
      };
      T * operator->() {return var;};
      T & operator*() {return *var;};
   private:
      T * var;
};

template <typename T>
class CUniqPtr
{
   public:
      CUniqPtr(){printf("CUniqPtr()\n");};
      ~CUniqPtr(){printf("~CUniqPtr()\n");};
      unique_ptr<T> getUniqPtr(T * ptrClass){ return unique_ptr<T>(ptrClass);};
};

struct SMyByte
{
   unsigned char bit0:1;
   unsigned char bit1:1;
   unsigned char bit2:1;
   unsigned char bit3:1;
   unsigned char bit4:1;
   unsigned char bit5:1;
   unsigned char bit6:1;
   unsigned char bit7:1;
   operator unsigned char ()
   {
      return (bit7<<7)+(bit6<<6)+(bit5<<5)+(bit4<<4)+(bit3<<3)+(bit2<<2)+(bit1<<1)+(bit0);
//       return (bit0<<7)+(bit1<<6)+(bit2<<5)+(bit3<<4)+(bit4<<3)+(bit5<<2)+(bit6<<1)+(bit7);
   };
};

#endif
