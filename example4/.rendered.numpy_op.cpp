

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

// struct buffer_info
// {
//   void *ptr;
//   size_t itemsize;
//   std::string format;
//   int ndim;
//   std::vector<size_t> shape;
//   std::vector<size_t> strides;
// }

// Passing in an array of doubles
void twice(pybind11::array_t<double> xs)
{
  pybind11::buffer_info info = xs.request();
  auto ptr = static_cast<double *>(info.ptr);

  int n = 1;
  for (auto r : info.shape)
  {
    n *= r;
  }

  for (int i = 0; i < n; i++)
  {
    *ptr++ *= 2;
  }
}

// Passing in a generic array
double sum(pybind11::array xs)
{
  pybind11::buffer_info info = xs.request();
  auto ptr = static_cast<double *>(info.ptr);

  int n = 1;
  for (auto r : info.shape)
  {
    n *= r;
  }

  double s = 0.0;
  for (int i = 0; i < n; i++)
  {
    s += *ptr++;
  }

  return s;
}

PYBIND11_PLUGIN(numpy_op)
{
  pybind11::module m("numpy_op", "auto-compiled c++ extension");
  m.def("sum", &sum);
  m.def("twice", &twice);
  return m.ptr();
}