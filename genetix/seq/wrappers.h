#ifndef WRAPPERS_H
#define WRAPPERS_H

PyObject *afreq_wrapper(PyObject *self, PyObject *args);
PyObject *all_contain_wrapper(PyObject *self, PyObject *args);
PyObject *cbase_wrapper(PyObject *self, PyObject *args);
PyObject *complement_wrapper(PyObject *self, PyObject *args);
PyObject *ctable_wrapper(PyObject *self, PyObject *args);
PyObject *delete_wrapper(PyObject *self, PyObject *args);
PyObject *is_dna_wrapper(PyObject *self, PyObject *args);
PyObject *is_protein_wrapper(PyObject *self, PyObject *args);
PyObject *is_rna_wrapper(PyObject *self, PyObject *args);
PyObject *mass_wrapper(PyObject *self, PyObject *args);
PyObject *mtable_wrapper(PyObject *self, PyObject *args);
PyObject *reverse_wrapper(PyObject *self, PyObject *args);
PyObject *reverse_complement_wrapper(PyObject *self, PyObject *args);
PyObject *shortest_seq_wrapper(PyObject *self, PyObject *args);
PyObject *transcribe_wrapper(PyObject *self, PyObject *args);
PyObject *transcribe_back_wrapper(PyObject *self, PyObject *args);
PyObject *translate_dna_wrapper(PyObject *self, PyObject *args);
PyObject *translate_rna_wrapper(PyObject *self, PyObject *args);

#endif
