

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

double square(double x)
{
  return x * x;
}

PYBIND11_PLUGIN(code)
{
  pybind11::module m("code", "auto-compiled c++ extension");
  m.def("square", pybind11::vectorize(square));
  return m.ptr();
}