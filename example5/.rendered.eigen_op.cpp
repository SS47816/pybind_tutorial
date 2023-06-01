;

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <Eigen/LU>

Eigen::MatrixXd inv(Eigen::MatrixXd xs)
{
  return xs.inverse();
}

double det(Eigen::MatrixXd xs)
{
  return xs.determinant();
}

PYBIND11_PLUGIN(eigen_op)
{
  pybind11::module m("eigen_op", "auto-compiled c++ extension");
  m.def("inv", &inv);
  m.def("det", &det);
  return m.ptr();
}