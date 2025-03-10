#include <pybind11/pybind11.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

int sub(int i, int j) {
    return i - j;
}

namespace py = pybind11;

PYBIND11_MODULE(math_tool, m) {
    m.def("add", &add);
    m.def("sub", &sub);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
