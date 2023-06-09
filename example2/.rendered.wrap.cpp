cfg['compiler_args'] = ['-std=c++11']
cfg['sources'] = ['funcs.cpp']
setup_pybind11(cfg)

#include <pybind11/pybind11.h>
#include "funcs.hpp"

namespace py = pybind11;

using namespace pybind11::literals;

PYBIND11_PLUGIN(wrap)
{
  py::module m("wrap", "pybind11 example plugin");
  m.def("add", &add, "A function which adds two numbers", "i"_a=1, "j"_a=2);
  return m.ptr();
}