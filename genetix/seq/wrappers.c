#include <Python.h>

#include "./afreq/afreq.h"
#include "./all_contain/all_contain.h"
#include "./cbase/cbase.h"
#include "./complement/complement.h"
#include "./ctable/ctable.h"
#include "./delete/delete.h"
#include "./is_dna/is_dna.h"
#include "./is_protein/is_protein.h"
#include "./is_rna/is_rna.h"
#include "./mass/mass.h"
#include "./mtable/mtable.h"
#include "./reverse/reverse.h"
#include "./reverse_complement/reverse_complement.h"
#include "./shortest_seq/shortest_seq.h"
#include "./transcribe/transcribe.h"
#include "./transcribe_back/transcribe_back.h"
#include "./translate_dna/translate_dna.h"
#include "./translate_rna/translate_rna.h"

PyObject *afreq_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    int fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = afreq(fin[0]);

    wout = Py_BuildValue("i", fout);

    return wout;
}

PyObject *all_contain_wrapper(PyObject *self, PyObject *args) {
    char **fin1;
    char *fin2;
    bool fout;

    PyObject *tmp;
    PyObject *item;
    PyObject *enc;

    int size;
    char *str;
    int i;

    if (!PyArg_ParseTuple(args, "O!s", &PyList_Type, &tmp, &fin2)) {
        return NULL;
    }

    size = PyList_Size(tmp);

    fin1 = malloc(size * sizeof(long));

    for (i = 0; i < size; i++) {
        item = PyList_GetItem(tmp, i);
        enc = PyUnicode_AsEncodedString(item, "utf-8", "~E~");
        str = PyBytes_AS_STRING(enc);
        Py_XDECREF(enc);
        fin1[i] = str;
    }

    fout = all_contain(fin1, size, fin2);

    free(fin1);

    if (fout) {
        Py_RETURN_TRUE;
    } else {
        Py_RETURN_FALSE;
    }
}

PyObject *cbase_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = cbase(fin[0]);

    wout = Py_BuildValue("s", (char[]){fout, '\0'});

    return wout;
}

PyObject *complement_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = complement(fin);

    wout = Py_BuildValue("s", fout);

    free(fout);

    return wout;
}

PyObject *ctable_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = ctable(fin);

    wout = Py_BuildValue("s", (char[]){fout, '\0'});

    return wout;
}

PyObject *delete_wrapper(PyObject *self, PyObject *args) {
    char *fin1;
    char *fin2;
    char *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "ss", &fin1, &fin2)) {
        return NULL;
    }

    fout = delete (fin1, fin2);

    wout = Py_BuildValue("s", fout);

    free(fout);

    return wout;
}

PyObject *is_dna_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    bool fout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = is_dna(fin);

    if (fout) {
        Py_RETURN_TRUE;
    } else {
        Py_RETURN_FALSE;
    }
}

PyObject *is_protein_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    bool fout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = is_protein(fin);

    if (fout) {
        Py_RETURN_TRUE;
    } else {
        Py_RETURN_FALSE;
    }
}

PyObject *is_rna_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    bool fout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = is_rna(fin);

    if (fout) {
        Py_RETURN_TRUE;
    } else {
        Py_RETURN_FALSE;
    }
}

PyObject *mass_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    double fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = mass(fin);

    wout = Py_BuildValue("d", fout);

    return wout;
}

PyObject *mtable_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    double fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = mtable(fin[0]);

    wout = Py_BuildValue("d", fout);

    return wout;
}

PyObject *reverse_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = reverse(fin);

    wout = Py_BuildValue("s", fout);

    free(fout);

    return wout;
}

PyObject *reverse_complement_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = reverse_complement(fin);

    wout = Py_BuildValue("s", fout);

    free(fout);

    return wout;
}

PyObject *shortest_seq_wrapper(PyObject *self, PyObject *args) {
    char **fin;
    int *fout;

    PyObject *wout;

    PyObject *tmp;
    PyObject *item;
    PyObject *enc;

    int size;
    char *str;
    int i;

    if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &tmp)) {
        return NULL;
    }

    size = PyList_Size(tmp);

    fin = malloc(size * sizeof(char *));

    for (i = 0; i < size; i++) {
        item = PyList_GetItem(tmp, i);
        enc = PyUnicode_AsEncodedString(item, "utf-8", "~E~");
        str = PyBytes_AS_STRING(enc);
        Py_XDECREF(enc);
        fin[i] = str;
    }

    fout = shortest_seq(fin, size);

    wout = Py_BuildValue("[ii]", 1, 1);

    free(fin);
    free(fout);

    return wout;
}

PyObject *transcribe_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = transcribe(fin);

    wout = Py_BuildValue("s", fout);

    free(fout);

    return wout;
}

PyObject *transcribe_back_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = transcribe_back(fin);

    wout = Py_BuildValue("s", fout);

    free(fout);

    return wout;
}

PyObject *translate_dna_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = translate_dna(fin);

    wout = Py_BuildValue("s", fout);

    free(fout);

    return wout;
}

PyObject *translate_rna_wrapper(PyObject *self, PyObject *args) {
    char *fin;
    char *fout;

    PyObject *wout;

    if (!PyArg_ParseTuple(args, "s", &fin)) {
        return NULL;
    }

    fout = translate_rna(fin);

    wout = Py_BuildValue("s", fout);

    free(fout);

    return wout;
}
