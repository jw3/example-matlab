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

TEST_CASE("to_struct") {
   std::vector<const char*> fields = {"a", "b", "c"};
   mwArray struk = toStruct(fields);

   // check number of fields
   REQUIRE(fields.size() == struk.NumberOfFields());

   // check each field
   int i = 0;
   for(const auto& f: fields) {
      REQUIRE(f == std::string(static_cast<const char*>(struk.GetFieldName(i++))));
   }
}

TEST_CASE("run") {
   MyPlugin p;
   p.run();
}
