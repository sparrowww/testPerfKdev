#include "testFile.hpp"
#include "testFile2.hpp"
#include "testFile3.hpp"

//---------------------------------------------------
   int main(int argc, char **argv) 
   {
      (void) argc; (void) argv;

//       TESTCLASS tstClObj;
//       TESTCLASS * tstCl = &tstClObj;

//       tstCl->stringAddTest();
//       tstCl->intAddTest();
// 
//       unsigned size = 100000;
//       tstCl->postIncrementTest(size);
//       tstCl->postIncrementTestWhile(size);
//       tstCl->preIncrementTest(size);
//       tstCl->preIncrementTestWhile(size);

//       tstCl->testStringCopy();

//       tstCl->testParentChild();
//       tstCl->testBinarySearch();
//       tstCl->testBinarySearchNum(5);
//       tstCl->testMyType();
//       tstCl->testUniqueCleverPointer();
//       tstCl->testSharedCleverPointer();
//       tstCl->testMyCleverPointer();
//       tstCl->testUniqueCleverPointer2();
//       tstCl->testBiteStruct();
//       tstCl->testCasting(MY_DCAST);
//       {
//          CMyThread objMyThread;
//          objMyThread.myPollingFuncMain();
//       }

//          {
//             CtestSize clObj;
//             clObj.setName("CtestSize");
//             clObj.testFunc();
//          }

         {
            CtestOperator clObj1;
            clObj1.setName("CtestOperator 1");
            CtestOperator clObj2;
            clObj2.setName("CtestOperator 2");
            CtestOperator clObj3;
            clObj3.setName("CtestOperator 3");
            clObj1.setVar(11);
            clObj2.setVar(10);
            if ( clObj1 > clObj2 )
            {
               printf ("OBJ1 > OBJ2!!!\n");
            }
            else
            {
               printf ("OBJ2 > OBJ1!!!\n");
            }
            CtestOperator *clObj1Ptr = new CtestOperator;
            clObj1Ptr->setName("FIRST");
            MyUniqPtr<CtestOperator> myUniq = MyUniqPtr<CtestOperator>(clObj1Ptr);
            myUniq->setName("SECOND");

            CtestOperator clObj4;
            clObj4.setName("CtestOperator 4");
            clObj1.setVar(2);
            clObj2.setVar(5);
            clObj4 = clObj1 + clObj2;
            clObj1.printVar();
            clObj2.printVar();
            clObj4.printVar("+");
            clObj4 = clObj1 - clObj1;
            clObj4.printVar("-");
            clObj4 = clObj1 * clObj2;
            clObj4.printVar("*");
            clObj4 = clObj2 / clObj1;
            clObj4.printVar("/");

         }

      return 0;
   };



