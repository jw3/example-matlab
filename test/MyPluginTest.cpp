#include <catch.hpp>
#include <MyPlugin.h>
#include <Array.h>

#include <pdal/PointView.hpp>
#include <pdal/ArtifactManager.hpp>

using namespace pdal;

using A = matlab::Array;

TEST_CASE("validate_parameters_pass") {
   PointTable t;
   PointViewPtr v = std::make_shared<PointView>(t);

   Options opts;
   opts.add("ten2twenty", 15);
   opts.add("nonempty", "foo");

   MyPlugin p;
   p.addOptions(opts);
   REQUIRE_NOTHROW(p.prepare(t));
}

TEST_CASE("validate_parameters_defaults") {
   PointTable t;
   PointViewPtr v = std::make_shared<PointView>(t);

   MyPlugin p;
   p.prepare(t);

   REQUIRE(p.m_args.notempty == "_");
   REQUIRE(p.m_args.ten2twenty == 12);
}

TEST_CASE("validate_parameters_fail") {
   PointTable t;
   PointViewPtr v = std::make_shared<PointView>(t);

   Options opts;
   opts.add("ten2twenty", 5);
   opts.add("nonempty", "foo");

   MyPlugin p;
   p.addOptions(opts);
   REQUIRE_THROWS(p.ready(t));
}

TEST_CASE("validate_artifacts") {
   PointTable t;
   PointViewPtr v = std::make_shared<PointView>(t);

   MyPlugin p;
   p.prepare(t);
   p.run(v);

   auto x = t.artifactManager().get<A>("ten2twenty");
   auto y = t.artifactManager().get<A>("nonempty");

   int ten2twenty = x->data.Get(1, 1);
   std::string nonempty = std::string(y->data.ToString());

   REQUIRE(ten2twenty == 12);
   REQUIRE(nonempty == "_");
}
