#include "MyPlugin.h"

#include <BuildInfo.hpp>
#include <SomeMccLib.h>

namespace pdal
{
   static PluginInfo const s_info{
         BuildInfo::PDALStageName,
         BuildInfo::PluginDescription,
         BuildInfo::PluginURL
   };

   CREATE_SHARED_STAGE(MyPlugin, s_info)

   std::string MyPlugin::getName() const {
      return s_info.name;
   }

   void MyPlugin::addArgs(ProgramArgs& args) {
      std::cout << BuildInfo::PDALStageName << "::addArgs" << std::endl;
   }

   void MyPlugin::ready(PointTableRef table) {
      std::cout << BuildInfo::PDALStageName << "::ready" << std::endl;
      initializeSomeMccLib();
   }

   PointViewSet MyPlugin::run(PointViewPtr view) {
      std::cout << BuildInfo::PDALStageName << "::run" << std::endl;

      mwArray ret;
      callSomeMccLib(1, ret, mwArray("0"), mwArray("1"));

      PointViewSet viewSet;
      viewSet.insert(view);
      return viewSet;
   }

   void MyPlugin::done(PointTableRef) {
      terminateSomeMccLib();
      std::cout << BuildInfo::PDALStageName << "::done" << std::endl;
   }
}

namespace util
{
   mwArray toArray(const std::string& str) {
      return mwArray(str.c_str());
   }

   mwArray toStruct(std::vector<const char*>& fieldNames) {
      auto sz = static_cast<int>(fieldNames.size());
      return mwArray(1, 1, sz, fieldNames.data());
   }
}
