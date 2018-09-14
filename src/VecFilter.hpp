#pragma once

#include <pdal/Filter.hpp>

namespace pdal
{
   struct PDAL_DLL VecFilter : public Filter
   {
      struct Args
      {
         int ival;
         std::vector<int> ivec;
         std::vector<double> dvec;
         std::vector<std::string> svec;
      };
      Args m_args;

      std::string getName() const override;

      void addArgs(ProgramArgs&) override;
      PointViewSet run(PointViewPtr) override;
   };
}
