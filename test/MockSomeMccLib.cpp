#include <SomeMccLib.h>

#include <iostream>

bool initializeSomeMccLib() {
   std::cout << "mocked: initializeSomeMccLib" << std::endl;
}

void callSomeMccLib(int retc, mwArray retv, mwArray p1, mwArray p2) {
   std::cout << "mocked: callSomeMccLib" << std::endl;
}

bool terminateSomeMccLib() {
   std::cout << "mocked: terminateSomeMccLib" << std::endl;
}
