#include <iostream>

#include <MatlabEngine.hpp>

using namespace matlab::engine;
using namespace matlab::data;

std::u16string convertAsciiToUtf16(const std::string& asciiStr);

int main(int c, char** v) {
    std::cout << "starting matlab" << std::endl;

    auto x = findMATLAB();

    std::cout << "found " << x.size() << " sessions" << std::endl;



    auto uengine = connectMATLAB(x.at(0)); // startMATLAB({u"-r 'matlab.engine.shareEngine'"});
    auto engine = std::shared_ptr<MATLABEngine>(std::move(uengine));


    ArrayFactory factory;
    TypedArray<double> doubles = factory.createArray<double>({3, 3},
                                                             {1.0, 2.0, 3.0,
                                                              4.0, 5.0, 6.0,
                                                              7.0, 8.0, 9.0});

//    engine->feval(u"addpath", 0,  {factory.createCharArray(u"/home/wassj/dev/code/gm/algorithms/PSU/Code"), factory.createCharArray(u"-end")} );
    engine->feval(u"myfn", 0, {});

    return 0;
}

std::u16string convertAsciiToUtf16(const std::string& asciiStr) {
    return std::u16string(asciiStr.cbegin(), asciiStr.cend());
}
