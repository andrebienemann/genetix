#include <Python.h>

#include "wrappers.h"

static PyMethodDef methods[] = {
    {
        "freq",
        (PyCFunction)freq_wrapper,
        METH_VARARGS,
    },
    {
        "gc_content",
        (PyCFunction)gc_content_wrapper,
        METH_VARARGS,
    },
    {
        "hamming_distance",
        (PyCFunction)hamming_distance_wrapper,
        METH_VARARGS,
    },
    {
        "titv_ratio",
        (PyCFunction)titv_ratio_wrapper,
        METH_VARARGS,
    },
    {
        NULL,
        NULL,
        0,
        NULL,
    },
};

static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "stat",
    "",
    -1,
    methods,
};

PyMODINIT_FUNC PyInit_stat(void) { return PyModule_Create(&module_def); }
