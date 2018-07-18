#include "MyPlugin.h"
#include "Array.h"

#include <pdal/ArtifactManager.hpp>

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
      args.add("ten2twenty", "number between 10 and 20", m_args.ten2twenty, 12);
      args.add("notempty", "a non empty string", m_args.notempty, "_");
   }

   void MyPlugin::ready(PointTableRef table) {
      std::cout << BuildInfo::PDALStageName << "::ready" << std::endl;
      initializeSomeMccLib();

      if(m_args.ten2twenty < 10 || m_args.ten2twenty > 20) throwError("ten2twenty must be between 10 and 20");
      if(m_args.notempty.empty()) throwError("notempty must not be empty");
   }

   PointViewSet MyPlugin::run(PointViewPtr view) {
      std::cout << BuildInfo::PDALStageName << "::run" << std::endl;

      mwArray ret;
      callSomeMccLib(1, ret, mwArray("0"), mwArray("1"));

      view->table().artifactManager().put("ten2twenty", matlab::mkarray(m_args.ten2twenty));
      view->table().artifactManager().put("notempty", matlab::mkarray(m_args.notempty));

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
