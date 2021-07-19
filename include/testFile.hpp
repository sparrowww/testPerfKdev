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
      myPointers(){ cout <<"myPointers()"<<endl;var = 0;};
      ~myPointers(){cout <<"~myPointers()"<<endl;};
      void setVar (int _var){var= _var;};
      int getVar (){return var;};
   private:
      int var;
};

#endif
