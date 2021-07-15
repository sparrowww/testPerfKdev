#ifndef TESTFILE_HPP
#define TESTFILE_HPP

#include <iostream>
#include <unistd.h>
using namespace std;

#include <chrono>
#include <ctime>
#include <ratio>
using namespace chrono;

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
   private:
      inline void startChronoTime ();
      inline void stopChronoTime ( string &text );
      high_resolution_clock::time_point difft1; ///< начальное время при запуске таймера
      high_resolution_clock::time_point difft2; ///< конечное время при остановке таймера
      duration<double, milli> time_span;
      string textToPrint;
};

#endif
