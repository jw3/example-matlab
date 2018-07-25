#include <VecFilter.hpp>

namespace pdal
{

   static PluginInfo const s_info{
         "filters.VecFilter",
         "",
         ""
   };

   CREATE_SHARED_STAGE(VecFilter, s_info)

   std::string VecFilter::getName() const {
      return s_info.name;
   }

   void VecFilter::addArgs(ProgramArgs& args) {
      args.add("vec", "just a vector of ints", m_args.vec, {1, 2, 3});
   }

   PointViewSet VecFilter::run(PointViewPtr view) {
      for(const auto& v: m_args.vec)
         std::cout << v << std::endl;

      PointViewSet viewSet;
      viewSet.insert(view);
      return viewSet;
   }
}
