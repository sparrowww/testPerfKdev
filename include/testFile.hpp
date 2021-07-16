#ifndef TESTFILE_HPP
#define TESTFILE_HPP

#include <iostream>
#include <unistd.h>
using namespace std;

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

#endif
