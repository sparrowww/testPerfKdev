#ifndef CCOUT_HPP
#define CCOUT_HPP

#include <iostream>
using namespace std;

class CCOUT
{
   public:
      template <typename T> void colorCOUT3 ( const T & text, const unsigned & color, bool flEndl )
      {
         //    30    31     32       33         34      35     36     37
         //  Black  Red   Green    Yellow[14]  Blue  Magenta  Cyan  White

         switch (color)
         {
            case 30:
               cout << BLACKCOLOR << text;
               break;
            case 31:
               cout << REDCOLOR << text;
               break;
            case 32:
               cout << GREENCOLOR << text;
               break;
            case 33:
               cout << YELLOWCOLOR << text;
               break;
            case 34:
               cout << BLUECOLOR << text;
               break;
            case 35:
               cout << MAGENTACOLOR << text;
               break;
            case 36:
               cout << CYANCOLOR << text;
               break;
            case 37:
               cout << WHITECOLOR << text;
               break;
            default:
               cout << REDCOLOR << text;
               break;
         };

         if ( flEndl )
         {
            cout << RESETCOLOR << endl;
         }
         else
         {
            cout << RESETCOLOR;
         };
      };
   private:
      const string BLACKCOLOR = "\033[30;1m";
      const string REDCOLOR = "\033[31;1m";
      const string GREENCOLOR = "\033[32;1m";
      const string YELLOWCOLOR = "\033[33;1m";
      const string BLUECOLOR = "\033[34;1m";
      const string MAGENTACOLOR = "\033[35;1m";
      const string CYANCOLOR = "\033[36;1m";
      const string WHITECOLOR = "\033[37;1m";
      const string RESETCOLOR = "\033[0m";

};

#endif


