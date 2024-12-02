using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;
//
#include "FizzBuzzCpp.h"
//

bool CFizzBuzzHelper::CFb::isDivisibleBy(int i, int intBy)
{
   return (i % intBy).Equals(0);
}

bool CFizzBuzzHelper::CFb::isDivisibleBy(KVP_I2S kvp)
{
   return isDivisibleBy(_i, kvp.Key);
}

CFizzBuzzHelper::CFb::CFb(int i)
{
   _i = i;
}

String^ CFizzBuzzHelper::GetVal(KVP_I2S kvp)
{
   return kvp.Value;
}

String^ CFizzBuzzHelper::Check(int i, IEnumerable<KVP_I2S>^ map)
{
   CFb^ cfb = gcnew CFb(i);

   return String::Join("",
      Enumerable::Select(Enumerable::Where(map, cfb->IsDivisibleBy),
         getVal));
}

IEnumerable<KVP_I2S>^ CFizzBuzzHelper::GetOutputList()
{
   return Enumerable::Select(_lst_int, mapIntToMap);
}

String^ CFizzBuzzHelper::GetOutput(KVP_I2S kvp)
{
   return String::Format("{0}\t{1}", kvp.Key,
      (String::IsNullOrEmpty(kvp.Value) ? kvp.Key.ToString() : kvp.Value));
}

KVP_I2S CFizzBuzzHelper::MapIntToMap(int i)
{
   return KVP_I2S(i, Check(i, _arr_kvp_s2i));
}

CFizzBuzzHelper::CFizzBuzzHelper(IEnumerable<int>^ lst_int, array<KVP_I2S, 1>^ arr_kvp_s2i)
{
   _lst_int = lst_int;
   _arr_kvp_s2i = arr_kvp_s2i;
}

/// <summary>
/// 
/// </summary>
/// <param name="map"></param>
/// <returns></returns>
String^ CFizzBuzzHelper::GetFormattedOutputString(IEnumerable<KVP_I2S>^ map)
{
   return String::Join("\r\n", Enumerable::Select(Enumerable::Select(_lst_int, mapIntToMap), getOutput));
}
