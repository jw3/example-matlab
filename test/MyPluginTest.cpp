#include <MyPlugin.h>
#include <array>

using namespace my;

int main(int c, char** v) {
   std::array<const char*, 2> args{"-nodesktop", "-nojvm"};
   mclInitializeApplication(args.data(), args.size());

   std::string expected = "__mystr__";
   mwArray actual = toArray(expected);

   const char* astr = actual.ToString();
   int res = std::string(astr) == expected;

   mclTerminateApplication();

   return !res;
}
