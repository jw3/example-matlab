#include <iostream>
#include <cstring>

#include <engine.h>


int main() {
    const double time[] = {0, 1, 2, 4, 5, 6, 7, 8, 9};

    Engine* engine = engOpen("");

    if (!engine) {
        std::cerr << "failed to init matlab" << std::endl;
        exit(1);
    }

    auto T = mxCreateDoubleMatrix(1, 10, mxREAL);
    memcpy(mxGetPr(T), time, sizeof(time));
    engPutVariable(engine, "T", T);

    engEvalString(engine, "D = .5.*(-9.8).*T.^2;");
    engEvalString(engine, "plot(T,D);");

    fgetc(stdin);
    engClose(engine);

    return 0;
}
