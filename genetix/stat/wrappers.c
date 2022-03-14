#include <Python.h>

#include "./freq/freq.h"
#include "./gc_content/gc_content.h"
#include "./hamming_distance/hamming_distance.h"
#include "./titv_ratio/titv_ratio.h"

PyObject *freq_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    int *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = freq(fin);

    wout = Py_BuildValue("{s:i,s:i,s:i,s:i}", "A", fout[0], "C", fout[1], "G",
                         fout[2], "T", fout[3]);

    free(fout);

    return wout;
}

PyObject *gc_content_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    double fout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = gc_content(fin);

    PyObject *wout = Py_BuildValue("d", fout);

    return wout;
}

PyObject *hamming_distance_wrapper(PyObject *self, PyObject *args) {
    char *fin1;
    char *fin2;
    int fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "ss", &fin1, &fin2)) {
        return NULL;
    }

    fout = hamming_distance(fin1, fin2);

    wout = Py_BuildValue("i", fout);

    return wout;
}

PyObject *titv_ratio_wrapper(PyObject *self, PyObject *args) {
    char *fin1;
    char *fin2;
    double fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "ss", &fin1, &fin2)) {
        return NULL;
    }

    fout = titv_ratio(fin1, fin2);

    wout = Py_BuildValue("d", fout);

    return wout;
}
