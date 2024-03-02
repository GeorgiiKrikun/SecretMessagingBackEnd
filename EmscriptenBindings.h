#ifndef EMSCRIPTENBINDINGS_H
#define EMSCRIPTENBINDINGS_H

#include <emscripten/bind.h>


class EMSDK_API
{
public:
    EMSDK_API();
    std::string create_secret(std::string secret);
    std::string extract_secret(std::string message);
    int add(int a, int b);
};

EMSCRIPTEN_BINDINGS(encoder_module) {
    emscripten::class_<EMSDK_API>("EmscriptenBindings")
        .constructor<>()
        .function("create_secret", &EMSDK_API::create_secret)
        .function("extract_secret", &EMSDK_API::extract_secret)
        .function("add", &EMSDK_API::add);
}

#endif // EMSCRIPTENBINDINGS_H
