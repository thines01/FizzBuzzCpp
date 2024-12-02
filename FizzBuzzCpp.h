#pragma once
using KVP_I2S = KeyValuePair<int, String^>;
public ref class CFizzBuzzHelper
{
private:
   property static array<KVP_I2S, 1>^ _arr_kvp_s2i;
   property static IEnumerable<int>^ _lst_int;

   ref class CFb
   {
   private:
      static property int _i;
      //
      static bool isDivisibleBy(int i, int intBy);
      static bool isDivisibleBy(KVP_I2S kvp);

   public:
      CFb(int i);
      Func<KVP_I2S, bool>^ IsDivisibleBy = gcnew Func<KVP_I2S, bool>(isDivisibleBy);
   };

   static String^ GetVal(KVP_I2S kvp);
   static String^ Check(int i, IEnumerable<KVP_I2S>^ map);
   static IEnumerable<KVP_I2S>^ GetOutputList();
   static String^ GetOutput(KVP_I2S kvp);
   static KVP_I2S MapIntToMap(int i);

private:
   static Func<KVP_I2S, String^>^ getVal = gcnew Func<KVP_I2S, String^>(GetVal);
   static Func<KVP_I2S, String^>^ getOutput = gcnew Func<KVP_I2S, String^>(GetOutput);
   static Func<int, KVP_I2S>^ mapIntToMap = gcnew Func<int, KVP_I2S>(MapIntToMap);

public:
   CFizzBuzzHelper(IEnumerable<int>^ lst_int, array<KVP_I2S, 1>^ arr_kvp_s2i);
   static String^ GetFormattedOutputString(IEnumerable<KVP_I2S>^ map);
};