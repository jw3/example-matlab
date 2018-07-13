#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>

#ifndef _MCLCPPCLASS_H_
#include <mclmcrrt.h>
#include <mclcppclass.h>
#endif

struct mcrListener : Catch::TestEventListenerBase
{
   using TestEventListenerBase::TestEventListenerBase;

   virtual void testCaseStarting(Catch::TestCaseInfo const& testInfo) override {
      std::array<const char*, 2> args{"-nodesktop", "-nojvm"};
      mclInitializeApplication(args.data(), args.size());
   }

   virtual void testCaseEnded(Catch::TestCaseStats const& testCaseStats) override {
      mclTerminateApplication();
   }
};
CATCH_REGISTER_LISTENER(mcrListener)
