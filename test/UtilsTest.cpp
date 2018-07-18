#include <catch.hpp>
#include <MyPlugin.h>

#include <array>

using namespace util;

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
