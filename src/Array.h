#pragma once

#include <pdal/Artifact.hpp>

#ifndef _MCLCPPCLASS_H_
#include <mclmcrrt.h>
#include <mclcppclass.h>
#endif

namespace matlab
{
   struct Array : public pdal::Artifact
   {
      Array() = default;
      Array(const mwArray& other) : data(other) {}
      mwArray data;
   };
   using ArrayPtr = std::shared_ptr<Array>;

   inline ArrayPtr mkarray(const std::string& str) {
      return std::make_shared<Array>(mwArray(str.c_str()));
   }

   template<typename T, class = typename std::enable_if<std::is_scalar<T>::value>::type>
   inline ArrayPtr mkarray(const T v) {
      return std::make_shared<Array>(mwArray(v));
   }
}
