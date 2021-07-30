#ifndef TESTFILE3_HPP
#define TESTFILE3_HPP

#include <iostream>
#include "unistd.h"
#include "pthread.h"

using namespace std;

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
      pthread_t  myPthread;
      void* ( *pthreadFuncName ) ( void* );
};

#endif
