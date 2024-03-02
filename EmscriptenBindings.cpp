#include "EmscriptenBindings.h"
#include "Encoder.h"

EMSDK_API::EMSDK_API() {}

std::string EMSDK_API::create_secret(std::string secret)
{
    return encoder::create_secret(secret);
}

std::string EMSDK_API::extract_secret(std::string message)
{
    return encoder::extract_secret(message);
}

int EMSDK_API::add(int a, int b)
{
    return a + b;
}
