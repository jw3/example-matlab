#pragma once

#include <string>
#include <vector>

#ifndef _MCLCPPCLASS_H_
#include <mclmcrrt.h>
#include <mclcppclass.h>
#endif

namespace my
{
   struct MyPlugin
   {
   };

   mwArray toArray(const std::string&);
   mwArray toStruct(std::vector<const char*>&);
}
