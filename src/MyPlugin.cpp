#include "MyPlugin.h"

namespace my
{
   mwArray toArray(const std::string& val) {
      return mwArray(val.c_str());
   }

}
