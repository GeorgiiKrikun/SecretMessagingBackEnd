#include <pybind11/pybind11.h>
#include "Encoder.h"

namespace py = pybind11;

PYBIND11_MODULE(secret_messaging, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("create_secret", &encoder::create_secret, "Create secret");
    m.def("extract_secret", &encoder::extract_secret, "Extract secret" );
}

