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
      printf ("i = %d\n", i);
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
//       delete mPtrCl;

      {
//          unique_ptr<myPointers> myUniqPtr (new myPointers());
         auto myUniqPtr = unique_ptr<myPointers>(mPtrCl);
         myUniqPtr->setVar(42);
         int var = (myUniqPtr.get())->getVar();
         printf("var = %d\n", var);
//          myUniqPtr.reset(nullptr);
         printf("END\n");
      }
      printf("EXIT\n");
   };

//---------------------------------------------------
   void TESTCLASS::testUniqueCleverPointer2()
   {
      printf("testUniqueCleverPointer2 BEGIN\n");
      CUniqPtr<myPointers> oCUniq; (void) oCUniq;

      {
//          auto uniqPtr = new myPointers();
//          auto uniqPtr = unique_ptr<myPointers>(new myPointers());
         auto uniqPtr = oCUniq.getUniqPtr(new myPointers());

         uniqPtr->setVar(777);
         uniqPtr->printVar();
      }
      printf("testUniqueCleverPointer2 END\n");
   };

//---------------------------------------------------
   void TESTCLASS::testSharedCleverPointer()
   {
//       myPointers * mPtr = new myPointers();
//       shared_ptr<myPointers> mySharedPtr (mPtr);
//       auto mySharedPtr = shared_ptr<myPointers>(mPtr);
      auto mySharedPtr = make_shared<myPointers>();
      mySharedPtr->setVar(11);
      int var = mySharedPtr->getVar();
      printf("var = %d\n", var);
//       {
         auto mySharedPtr2 = shared_ptr<myPointers>(mySharedPtr);
         var = mySharedPtr2->getVar();
         printf("var2 = %d\n", var);
//       }

//       {
         auto mySharedPtr3 = shared_ptr<myPointers>(mySharedPtr);
         var = mySharedPtr3->getVar();
         printf("var3 = %d\n", var);
//       }
      var = mySharedPtr->getVar();
      printf("var4 = %d\n", var);
      long int count = mySharedPtr.use_count();
      printf("EXIT, count = %ld\n", count);
   };

//---------------------------------------------------
   void TESTCLASS::testMyCleverPointer ()
   {
      myPointers * mPtr = new myPointers();

      myClPtr<myPointers> myCleverPtr = myClPtr<myPointers>(mPtr);

      if ( myCleverPtr->getInstance() == nullptr )
      {
         return;
      }
      myCleverPtr->setVar(69);
      (*myCleverPtr).printVar();

      int myVar = myCleverPtr->getVar();
      if ( myVar != 100)
      {
         printf("myVar!=100, myVar=%d\n", myVar);
         return;
      }

      delete mPtr;
      mPtr = nullptr;
   };

   //---------------------------------------------------
   void TESTCLASS::testBiteStruct ()
   {
      ///NOTE           0 1 2 3 4 5 6 7
      SMyByte oSMyByte {0,0,0,1,1,0,1,0};
      int sizeStr = sizeof(oSMyByte);
      printf("testBiteStruct:::sizeStr = %d\n", sizeStr);
      printf("testBiteStruct:::oSMyByte.bit0 = %d\n", oSMyByte.bit0);
      printf("testBiteStruct:::oSMyByte.bit1 = %d\n", oSMyByte.bit1);
      printf("testBiteStruct:::oSMyByte.bit2 = %d\n", oSMyByte.bit2);
      printf("testBiteStruct:::oSMyByte.bit3 = %d\n", oSMyByte.bit3);
      printf("testBiteStruct:::oSMyByte.bit4 = %d\n", oSMyByte.bit4);
      printf("testBiteStruct:::oSMyByte.bit5 = %d\n", oSMyByte.bit5);
      printf("testBiteStruct:::oSMyByte.bit6 = %d\n", oSMyByte.bit6);
      printf("testBiteStruct:::oSMyByte.bit7 = %d\n", oSMyByte.bit7);
      printf("testBiteStruct:::oSMyByte = %x\n", oSMyByte.operator unsigned char());
   };

   //---------------------------------------------------
   void TESTCLASS::testCasting(MY_ECASTTYPE eCastType)
   {
      switch (eCastType)
      {
         case MY_CTYPE:
            printf("Cstyle BEGIN\n");
            {
               int i = 1;
               int * pi = nullptr;
               const int ci = 11;
               float f = 5.2;
               i = (int)f;
               cout << "Cstyle i = " << i << endl;
               pi = (int*)&ci;
               cout << "Cstyle *pi = " << *pi << endl;
            }
            printf("Cstyle END\n");
            break;
         case MY_RCAST:
            printf("reinterpret_cast BEGIN\n");
            {
               int iVar = 10;
               int * pIVar = nullptr;
               cout << "pIVar = " << pIVar << endl;
               pIVar = reinterpret_cast<int*>(iVar);
               cout << "reinterpret_cast pIVar = " << pIVar << endl;
            }
            printf("reinterpret_cast END\n");
            break;
         case MY_CONSTCAST:
            printf("const_cast BEGIN\n");
            {
               const int constIVar = 111;
               auto la = [](const int * cI){ cout <<"LAMBDA = " << *cI << endl;};
               la (&constIVar);
               int noConstIVar = 12;
               auto constIVar2 = const_cast<const int*>(&noConstIVar);
               la (constIVar2);
               auto noConstIVar2 = const_cast<int*>(&constIVar);
               (*noConstIVar2)+=1;
               la (noConstIVar2);
            }
            printf("const_cast END\n");
            break;
         case MY_SCAST:
            printf("static_cast BEGIN\n");
            {
               int iVar = 2;
               MY_ECASTTYPE mEVar;
               mEVar = static_cast<MY_ECASTTYPE>(iVar);
               cout << "mEVar = " << mEVar << endl;
            }
            printf("static_cast END\n");
            break;
         case MY_DCAST:
            printf("dynamic_cast BEGIN\n");
            {
               class CA {};
               class CAchild:public CA {};
               class CB { public: virtual ~CB(){};};
               class CBchild:public CB {};
               class CBchild2:public CB {};
               CA ca;
               CA * pca = &ca;
               CB cb;
               CB * pcb = &cb;
               CAchild cac;
               CAchild * pcac = &cac;
               CBchild cbc;
               CBchild * pcbc = &cbc;
               CBchild2 cbc2;
               CBchild2 * pcbc2 = &cbc2;
               pcb = dynamic_cast<CB *>(pcbc); cout<<"pcbc PTR = " << pcbc <<endl; cout<<"pcb PTR = " << pcb <<endl;
               pcbc2 = dynamic_cast<CBchild2 *>(pcb); cout<<"pcbc2 PTR = " << pcbc2 <<endl;
               if (pcbc2 == nullptr)
               {
                  cout<<"FAIL"<<endl;//Ошибка на этапе выполнения!!!
               }
            }
            printf("dynamic_cast END\n");
            break;
         default:
            printf("НЕ ВЫБРАН ТИП ПРИВЕДЕНИЯ ТИПА!!!\n");
            break;
      };
   };

