
<%
cfg['compiler_args'] = ['-std=c++17']
setup_pybind11(cfg)
%>;

#include <pybind11/pybind11.h>

struct Pet {
  Pet(const std::string &name) : name(name) { }
  void setName(const std::string &name_) { name = name_; }
  const std::string &getName() const { return name; }

  std::string name;
};

namespace py = pybind11;

PYBIND11_MODULE(pet, m) {
  py::class_<Pet>(m, "Pet")
    .def(py::init<const std::string &>())
    .def("setName", &Pet::setName)
    .def("getName", &Pet::getName);
}