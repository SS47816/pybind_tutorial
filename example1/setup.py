import os, sys

from distutils.core import setup, Extension
from distutils import sysconfig

cpp_args = ['-std=c++11']

ext_modules = [
  Extension(
    'wrap',
    ['funcs.cpp', 'wrap.cpp'],
    include_dirs = ['pybind11/include'],
    language = 'c++',
    extra_compile_args = cpp_args,
  ),
]

setup(
  name = 'wrap',
  version = '0.0.1',
  author = 'SS47816',
  author_email = 'ss1057532022@gmail.com',
  description = 'Example',
  ext_modules = ext_modules,
)