#include "MyPlugin.h"

#include <BuildInfo.hpp>
#include <SomeMccLib.h>

namespace my
{
   void MyPlugin::run() {
      initializeSomeMccLib();
      mwArray ret;
      callSomeMccLib(1, ret, mwArray("0"), mwArray("1"));
      terminateSomeMccLib();
   }

   mwArray toArray(const std::string& str) {
      return mwArray(str.c_str());
   }

   mwArray toStruct(std::vector<const char*>& fieldNames) {
      auto sz = static_cast<int>(fieldNames.size());
      return mwArray(1, 1, sz, fieldNames.data());
   }
}
