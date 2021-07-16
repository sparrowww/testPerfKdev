#include "testFile.hpp"

//---------------------------------------------------
   int main(int argc, char **argv)
   {
      (void) argc; (void) argv;

      TESTCLASS * tstCl = new TESTCLASS();

      tstCl->stringAddTest();
      tstCl->intAddTest();

      unsigned size = 100000;
      tstCl->postIncrementTest(size);
      tstCl->postIncrementTestWhile(size);
      tstCl->preIncrementTest(size);
      tstCl->preIncrementTestWhile(size);

      delete tstCl;
      tstCl = nullptr;

      return 0;
   };

