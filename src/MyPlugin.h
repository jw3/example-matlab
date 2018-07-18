#pragma once

#include <string>
#include <vector>

#ifndef _MCLCPPCLASS_H_
#include <mclmcrrt.h>
#include <mclcppclass.h>
#endif

#include <pdal/Filter.hpp>

namespace pdal
{
   struct PDAL_DLL MyPlugin : public Filter
   {
      std::string getName() const override;

      struct Args
      {
         int ten2twenty;
         std::string notempty;
         std::vector<int> vecparam;
      };
      Args m_args;

      void addArgs(ProgramArgs&) override;
      void ready(PointTableRef) override;
      PointViewSet run(PointViewPtr) override;
      void done(PointTableRef) override;
   };
}

namespace util
{
   mwArray toArray(const std::string&);
   mwArray toStruct(std::vector<const char*>&);
}
