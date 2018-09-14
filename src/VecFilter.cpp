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
      args.add("ival", "just an int", m_args.ival, 999);
      args.add("ivec", "just a vector of ints", m_args.ivec, {0, -1});
      args.add("dvec", "just a vector of doubles", m_args.dvec, {0.0, -1.1});
      args.add("svec", "just a vector of strings", m_args.svec, {"is","mt"});

      std::string filename;
      args.add("filename", "", filename, "");
   }

   PointViewSet VecFilter::run(PointViewPtr view) {
      std::cout << "ival=" << m_args.ival << std::endl;

      for(const auto& v: m_args.ivec)
         std::cout << v << std::endl;

      for(const auto& v: m_args.dvec)
         std::cout << v << std::endl;

      for(const auto& v: m_args.svec)
         std::cout << v << std::endl;

      PointViewSet viewSet;
      viewSet.insert(view);
      return viewSet;
   }
}
