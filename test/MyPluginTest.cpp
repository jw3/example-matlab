#include <MyPlugin.h>
#include <array>

#include <catch.hpp>

using namespace my;

TEST_CASE("string_to_array") {
   std::string expected = "__mystr__";
   mwArray actual = toArray(expected);

   const char* astr = actual.ToString();

   REQUIRE(std::string(astr) == expected);
}
