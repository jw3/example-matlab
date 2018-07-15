#include <catch.hpp>
#include <MyPlugin.h>

#include <pdal/PointView.hpp>

using namespace pdal;

TEST_CASE("run") {
   PointTable t;
   PointViewPtr v = std::make_shared<PointView>(t);

   MyPlugin p;
   p.ready(t);
   p.run(v);

   REQUIRE(true);
}
