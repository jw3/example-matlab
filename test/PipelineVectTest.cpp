#include <catch.hpp>

#include <pdal/util/FileUtils.hpp>
#include <pdal/PipelineManager.hpp>
#include <pdal/PipelineReaderJSON.hpp>

#include <string>

using namespace pdal;

TEST_CASE("basic") {
   PipelineManager mgr;
   PipelineReaderJSON rdr(mgr);

   std::stringstream ss;
   ss << R"({"pipeline" : [{ "type":"filters.VecFilter" , "vec":1 }] })";
   mgr.readPipeline(ss);

   mgr.getMetadata().findChild("foo.bar");
}
