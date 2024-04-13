from setuptools import setup, Extension
import pybind11

setup(
    name='secret_messaging',
    version='0.1',
    ext_modules=[
        Extension(
            'secret_messaging',
            ['PyBindBindings.cpp', 'Encoder.cpp'],
            include_dirs=[pybind11.get_include()],
            language='c++'
        ),
    ],
)