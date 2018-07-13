#include "MyPlugin.h"

namespace my
{
   mwArray toArray(const std::string& str) {
      return mwArray(str.c_str());
   }

   mwArray toStruct(std::vector<const char*>& fieldNames) {
      auto sz = static_cast<int>(fieldNames.size());
      return mwArray(1, 1, sz, fieldNames.data());
   }
}
