using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;
//
using KVP_I2S = KeyValuePair<int, String^>;
//
#include "FizzBuzzCpp.h"

void main(void)
{
   IEnumerable<int>^ lst_int = Enumerable::Range(1, 100);

   array<KVP_I2S, 1>^ arr_kvp_s2i =
   {
      KeyValuePair<int, String^>(3, "Fizz"),
      KeyValuePair<int, String^>(5, "Buzz"),
      KeyValuePair<int, String^>(7, "Bang")
   };

   CFizzBuzzHelper^ fbh = gcnew CFizzBuzzHelper(lst_int, arr_kvp_s2i);
   Console::WriteLine(fbh->GetFormattedOutputString(arr_kvp_s2i));
}
