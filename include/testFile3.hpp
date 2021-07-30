#ifndef TESTFILE3_HPP
#define TESTFILE3_HPP

#include <iostream>
#include "unistd.h"
#include "pthread.h"

#include <chrono>
#include <ctime>
#include <ratio>

using namespace std;

using namespace chrono;

#define msleep(us) usleep(us*1000)

class CMyThread
{
   public:
      CMyThread(){printf("CMyThread constr\n");};
      ~CMyThread(){printf("CMyThread destr\n");};
      void myPollingFuncMain();
      void myPollingFuncThread();
      void startPthread();
   private:
      void* ( *pthreadFuncName ) ( void* );
      inline void startChronoTime ();
      inline double stopChronoTime ( const string &text );
      unsigned short crc16Static ( unsigned short &data );
      unsigned short crc16NoStatic ( unsigned short &data );
   private:
      pthread_t  myPthread;
      high_resolution_clock::time_point difft1; ///< начальное время при запуске таймера
      high_resolution_clock::time_point difft2; ///< конечное время при остановке таймера
      duration<double, milli> time_span;
};

#endif
