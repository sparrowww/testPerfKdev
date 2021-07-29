#ifndef TESTFILE2_HPP
#define TESTFILE2_HPP

#include "iostream"
using namespace std;

class TESTCLASS2
{
   public:
      TESTCLASS2( ){};
      virtual ~TESTCLASS2(){};
      virtual void testFunc() = 0;
   protected:
      string nameClass;
};

class CtestSize: public TESTCLASS2
{
   public:
      CtestSize(){};
      CtestSize(string _name){nameClass = _name; cout <<nameClass.c_str()<< " BEGIN"<< endl;};
      virtual ~CtestSize(){cout <<nameClass.c_str()<< " END"<< endl;};
      virtual void testFunc();
};

#endif
