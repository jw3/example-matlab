#include <iostream>

#include <libwmex.h>

int main(int c, char** v) {
    std::cout << "init mcr" << std::endl;

    const char* args[] = {"-nodisplay"};
    if (!mclInitializeApplication(args, 1)) {
        std::cerr << "\t---> failed to init mcr" << std::endl;
    }

    libwmexInitialize();

    wmex();


    return 0;
}
