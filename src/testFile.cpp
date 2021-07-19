#include "testFile.hpp"
#include <parallel/for_each.h>
#include <parallel/for_each.h>

//---------------------------------------------------
   TESTCLASS::TESTCLASS()
   {
      ccout = new CCOUT;

   };

//---------------------------------------------------
   TESTCLASS::~TESTCLASS()
   {
      delete ccout;
   };

//---------------------------------------------------
   inline void TESTCLASS::startChronoTime ()
   {
      difft1 =  high_resolution_clock::now();
   };

//---------------------------------------------------
   inline void TESTCLASS::stopChronoTime ( string &text )
   {
      difft2 = high_resolution_clock::now();

      time_span = difft2 - difft1;

      cout << "\033[34;1m(" << text.c_str() <<") DIF TIME (MS) = "
      << time_span.count()<<" \033[0m" << endl;
   };

//---------------------------------------------------
   void TESTCLASS::colorCOUT ( string text, short color, bool flEndl )
   {

//    30    31     32       33         34      35     36     37
//  Black  Red   Green    Yellow[14]  Blue  Magenta  Cyan  White
      cout << "\033[" << color << ";1m";
      cout /*<< getDate().c_str()*/ << "|||   ";
      cout << text.c_str();
      if ( flEndl )
      {
         cout << "\033[0m" << endl;
      }
      else
      {
         cout << "\033[0m";
      }
   };

//---------------------------------------------------
   void TESTCLASS::colorCOUT2 ( string &text, short color, bool flEndl )
   {

//    30    31     32       33         34      35     36     37
//  Black  Red   Green    Yellow[14]  Blue  Magenta  Cyan  White
      cout << "\033[" << color << ";1m";
      cout /*<< getDate().c_str()*/ << "|||   ";
      cout << text.c_str();
      if ( flEndl )
      {
         cout << "\033[0m" << endl;
      }
      else
      {
         cout << "\033[0m";
      }
   };

//---------------------------------------------------
   void TESTCLASS::testStringCopy()
   {
      textToPrint = "testStringCopy";

      string tmpS = "testStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopy";

      startChronoTime();
      colorCOUT(tmpS,32,true);
      stopChronoTime(textToPrint);

      tmpS.append("2");
      textToPrint.append("2");

      startChronoTime();
      colorCOUT2(tmpS,32,true);
      stopChronoTime(textToPrint);

      tmpS.pop_back();
      tmpS.append("3");
      textToPrint.pop_back();
      textToPrint.append("3");

      startChronoTime();
      ccout->colorCOUT3(tmpS,32,true);
      stopChronoTime(textToPrint);

      textToPrint.pop_back();
      textToPrint.append("4");

      startChronoTime();
      ccout->colorCOUT3("testStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopytestStringCopy",32,true);
      stopChronoTime(textToPrint);

      ccout->colorCOUT3(1,30,false);
      ccout->colorCOUT3("2",31,false);
      ccout->colorCOUT3(0.009,32,false);
      ccout->colorCOUT3('a',33,false);
      ccout->colorCOUT3(2123,34,false);
      ccout->colorCOUT3(-0.8,35,false);
      ccout->colorCOUT3("qweqe",36,false);
      ccout->colorCOUT3('b',37,true);
   };

//---------------------------------------------------
   void TESTCLASS::stringAddTest ()
   {
      textToPrint = "stringAddTest (+++)";
      string s1 = "1";
      string s2 = "2";
      string s3 = "3";

      startChronoTime();
      string s = s1 + s2 + s3;
//       printf ("s = %s\n", s.c_str());
      stopChronoTime(textToPrint);

      textToPrint = "stringAddTest (+=+=)";
      string s4 = "4";
      string s5 = "5";
      string s6 = "6";

      startChronoTime();
      string ss = s4;
      ss += s5;
      ss += s6;
//       printf ("ss = %s\n", ss.c_str());
      stopChronoTime(textToPrint);
   };

//---------------------------------------------------
   void TESTCLASS::intAddTest ()
   {
      textToPrint = "intAddTest (+++)";
      int i1 = 1;
      int i2 = 2;
      int i3 = 3;

      startChronoTime();
      int i = i1 + i2 + i3;
//       printf ("i = %d\n", i);
      stopChronoTime(textToPrint);

      textToPrint = "intAddTest (+=+=)";
      int i4 = 4;
      int i5 = 5;
      int i6 = 6;

      startChronoTime();
      int ii = i4;
      ii += i5;
      ii += i6;
//       printf ("ii = %d\n", ii);
      stopChronoTime(textToPrint);
   };

//---------------------------------------------------
   void TESTCLASS::postIncrementTest ( unsigned numInc )
   {
      textToPrint = "postIncrementTest";
      string str;
      startChronoTime();
      for ( unsigned counter = 0; counter < numInc; counter++ )
      {
         str.append(to_string(counter));
      }
      stopChronoTime(textToPrint);
   };

//---------------------------------------------------
   void TESTCLASS::postIncrementTestWhile ( unsigned numInc )
   {
      textToPrint = "postIncrementTestWhile";
      string str;
      startChronoTime();
      unsigned counter = 0;
      while ( counter < numInc )
      {
         str.append(to_string(counter));
         counter++;
      }

      stopChronoTime(textToPrint);
   };

   //---------------------------------------------------
   void TESTCLASS::preIncrementTest ( unsigned numInc )
   {
      textToPrint = "preIncrementTest";
      startChronoTime();
      string str;
      startChronoTime();
      for ( unsigned counter = 0; counter < numInc; ++counter )
      {
         str.append(to_string(counter));
      }
      stopChronoTime(textToPrint);
   };

   //---------------------------------------------------
   void TESTCLASS::preIncrementTestWhile ( unsigned numInc )
   {
      textToPrint = "preIncrementTestWhile";
      startChronoTime();
      string str;
      startChronoTime();
      unsigned counter = 0;
      while (  counter < numInc )
      {
         str.append(to_string(counter));
         ++counter;
      }
      stopChronoTime(textToPrint);
   };

   //---------------------------------------------------
   void TESTCLASS::testParentChild()
   {
      A * a = new A();
      a->changeNumber();
      delete a;
      a = nullptr;

      cout << endl;

      B * b = new B();
      b->changeNumber();
      delete b;
      b = nullptr;

      cout << endl;

      A * ab = new B();
      ab->changeNumber();
      delete ab;
      ab = nullptr;
   };

//---------------------------------------------------
   void TESTCLASS::testBinarySearch()
   {
      int arrInt[] = {10,49,34,1};

      for_each(begin(arrInt), end(arrInt), [](int & element){ cout << element<<"|";}); cout << endl;
      sort(begin(arrInt), end(arrInt), [](int &a, int&b){ return a<b;});
      for_each(begin(arrInt), end(arrInt), [](int & element){ cout << element<<"|";}); cout << endl;
      bool resSearch = binary_search(begin(arrInt), end(arrInt), arrInt[2]); cout << "resSearch = "<< resSearch<< endl;
   };

//---------------------------------------------------
   void TESTCLASS::testBinarySearchNum( int num )
   {
      const unsigned sizeVec = 10;
      vector <int> vecInt;
      int numTry = 0;
      bool res = false;
      while ( 1 )
      {
         srand(time(nullptr));
         vecInt.clear();
         for ( unsigned i = 0; i < sizeVec; ++i )
         {
            vecInt.push_back(rand()%100);
         }

         sort(vecInt.begin(), vecInt.end());
         for_each(vecInt.begin(), vecInt.end(), [&](int i){cout << i<<"|";});cout << endl;
         res = binary_search(vecInt.begin(), vecInt.end(), num);
         numTry++;

         if ( res )
         {
            break;
         }
         sleep (1);
      };

      cout << "numTry = " << numTry << endl;

   };

//---------------------------------------------------
   void TESTCLASS::testMyType()
   {
      srand(time(nullptr));
      myClass mCL;
      mCL.setA(rand()%100);
      mCL.printAEndl("mCL");
      myClass mCL2(mCL);
      mCL2.printAEndl("mCL2");
      myClass mCL3;
      mCL3 = mCL2;
      mCL3.printAEndl("mCL3");

      mCL.setA(rand()%100);srand(rand()%100);
      mCL2.setA(rand()%100);srand(rand()%100);
      mCL3.setA(rand()%100);
      vector <myClass> myVec;
      int i =0;
      const int sizeVec = 50;
      myClass *mclPtr[sizeVec];
      cout << "BEFORE"<< endl;
      while ( i<sizeVec )
      {
         mclPtr[i] = new myClass();
         mclPtr[i]->setA(rand()%100);srand(rand()%100);
         mclPtr[i]->printA();
         myVec.push_back(*mclPtr[i]);
         ++i;
      }
      cout << endl;

      cout << "AFTER SORT"<< endl;
      sort(myVec.begin(), myVec.end());
      for_each(myVec.begin(), myVec.end(),[](myClass & _mCl){ _mCl.printA();});
      cout << endl;

      i =0;
      while ( i<sizeVec )
      {
         delete mclPtr[i];
         ++i;
      }

   };

//---------------------------------------------------
   void TESTCLASS::testUniqueCleverPointer()
   {
      myPointers * mPtrCl = new myPointers();
      delete mPtrCl;

      {
//          unique_ptr<myPointers> myCleverPtr (new myPointers());
         auto myCleverPtr = unique_ptr<myPointers>(new myPointers());
         myCleverPtr->setVar(42);
         int var = (myCleverPtr.get())->getVar();
         printf("var = %d\n", var);
//          myCleverPtr.reset(nullptr);
         printf("EXIT\n");
      }
      printf("END\n");
   };



