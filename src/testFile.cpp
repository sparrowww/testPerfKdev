#include "testFile.hpp"

//---------------------------------------------------
   TESTCLASS::TESTCLASS()
   {

   };

//---------------------------------------------------
   TESTCLASS::~TESTCLASS()
   {

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



