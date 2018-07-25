#pragma once

#include <pdal/Filter.hpp>

namespace pdal
{
   struct PDAL_DLL VecFilter : public Filter
   {
      struct Args
      {
         std::vector<int> vec;
      };
      Args m_args;

      std::string getName() const override;

      void addArgs(ProgramArgs&) override;
      PointViewSet run(PointViewPtr) override;
   };
}
