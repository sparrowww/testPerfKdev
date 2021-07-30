#include "testFile3.hpp"

void CMyThread::myPollingFuncMain()
{
   startPthread();
   unsigned short counter = 0;
   while (1)
   {
//       cout << "myPollingFuncMain count = " << counter << endl;
      counter++;
      counter &= 0xffff;
      sleep(1);
   };
};

void * myWorkFunc( void * p )
{
   CMyThread * myThr = ( CMyThread * ) p;
   myThr->myPollingFuncThread();
   return NULL;
};

void CMyThread::startPthread()
{
   pthreadFuncName = myWorkFunc;
   pthread_create ( &myPthread, NULL, pthreadFuncName, ( void* ) this );
};

void CMyThread::myPollingFuncThread()
{
   unsigned short counter = 0;
   auto lCounter = [](unsigned short & _c){cout << "count = " << _c << endl;_c++;_c&=0xff;};

   while (1)
   {
      lCounter(counter);
      msleep(20);
   };
};




