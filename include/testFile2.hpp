#ifndef TESTFILE2_HPP
#define TESTFILE2_HPP

#include "iostream"
using namespace std;

class TESTCLASS2
{
   public:
      TESTCLASS2( ){};
      virtual ~TESTCLASS2(){cout <<nameClass.c_str()<< " END"<< endl;};
      void setName(string _name){nameClass = _name;cout << "SET NAME:::"<<nameClass.c_str()<< endl;};
      virtual void testFunc() = 0;
   protected:
      string nameClass {"EMPTYNAME"};
};

class CtestSize: public TESTCLASS2
{
   public:
      CtestSize(){};
      virtual ~CtestSize(){;};
      virtual void testFunc();
   private:
      typedef struct
      {
         char char1 {};
         char char2 {};
         char char3 {};
         char char4 {};
         int size(){return sizeof(MyStruct);};
      } MyStruct;

      class CSizeCheck
      {
         public:
            CSizeCheck(){setVar1();};
            int getVar1(){return var1;};
         private:
            void setVar1(){srand(time(nullptr));var1 = rand()%1000;};
            int var1 {};
      };
};

class CtestOperator: public TESTCLASS2
{
   public:
      CtestOperator(){};
      CtestOperator(int _var){var = _var;};
      virtual ~CtestOperator(){;};
      virtual void testFunc(){};
      bool operator > (const CtestOperator & arg){ return (var > arg.var)?true:false;};
      bool operator < (const CtestOperator & arg){ return (var < arg.var)?true:false;};
      bool operator >= (const CtestOperator & arg){ return (var >= arg.var)?true:false;};
      bool operator <= (const CtestOperator & arg){ return (var <= arg.var)?true:false;};
      bool operator == (const CtestOperator & arg){ return (var == arg.var)?true:false;};
      CtestOperator& operator= (const CtestOperator &arg)
      {
//          nameClass = arg.nameClass;
         var = arg.var;
         return *this;
      }
      friend const CtestOperator operator + (const CtestOperator & arg1, const CtestOperator & arg2){ return CtestOperator(arg1.var + arg2.var);};
      friend const CtestOperator operator - (const CtestOperator & arg1, const CtestOperator & arg2){ return CtestOperator(arg1.var - arg2.var);};
      friend const CtestOperator operator * (const CtestOperator & arg1, const CtestOperator & arg2){ return CtestOperator(arg1.var * arg2.var);};
      friend const CtestOperator operator / (const CtestOperator & arg1, const CtestOperator & arg2){ return CtestOperator(arg1.var / arg2.var);};
      void setVar( int _var){ var = _var;};
      void printVar( const string & str = "" ){printf ("\{%s}var===%d\n",str.c_str(), var);};
   private:
      int var {};
};

template <typename T>
class MyUniqPtr
{
   public:
      MyUniqPtr(T * ptr){PTR = ptr;};
      ~MyUniqPtr(){delete PTR;};
      T * operator -> (){return PTR;};
      T & operator * (){return *PTR;};
   private:
      T * PTR {nullptr};
};

#endif
