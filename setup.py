#!/usr/bin/env python
from setuptools import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
import numpy

ext_modules = [ 
        Extension(
            name = "yin",
            sources = ["src/ypt.pyx", "src/Yin.c"],
            include_dirs = [ numpy.get_include() ],
            language = "c",
            )
        ]

setup(name='yin',
    version = "0.1",
    description='A python wrapper to the YIN pitch algorithm',
      long_description='''\
    A wrapper to the Yin algorithm, a well-established autocorrelation 
	based pitch algorith.''',
      author='Christopher Brown',
      author_email='cbrown1@pitt.edu',
      maintainer='Christopher Brown',
      maintainer_email='cbrown1@pitt.edu',
      url='http://pyin.googlecode.com',
    cmdclass = {'build_ext':build_ext},
    ext_modules = ext_modules
)
