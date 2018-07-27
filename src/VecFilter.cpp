#include <VecFilter.hpp>

namespace pdal
{

   static PluginInfo const s_info{
         "filters.vec",
         "",
         ""
   };

   CREATE_SHARED_STAGE(VecFilter, s_info)

   std::string VecFilter::getName() const {
      return s_info.name;
   }

   void VecFilter::addArgs(ProgramArgs& args) {
      args.add("ivec", "just a vector of ints", m_args.ivec, {-1});
      args.add("svec", "just a vector of strings", m_args.svec, {"mt"});
   }

   PointViewSet VecFilter::run(PointViewPtr view) {
      for(const auto& v: m_args.ivec)
         std::cout << v << std::endl;

      for(const auto& v: m_args.svec)
         std::cout << v << std::endl;

      PointViewSet viewSet;
      viewSet.insert(view);
      return viewSet;
   }
}
