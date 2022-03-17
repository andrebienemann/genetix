from unittest import TestCase

from genetix.seq import (
    afreq,
    cbase,
    complement,
    ctable,
    delete,
    is_dna,
    is_protein,
    is_rna,
    mass,
    mtable,
    reverse,
    reverse_complement,
    transcribe,
    transcribe_back,
    translate_dna,
    translate_rna,
)


class TestSeq(TestCase):
    def test_afreq(self):
        self.assertEqual(4, afreq("A"))
        self.assertEqual(2, afreq("C"))
        self.assertEqual(2, afreq("D"))
        self.assertEqual(2, afreq("E"))
        self.assertEqual(2, afreq("F"))
        self.assertEqual(4, afreq("G"))
        self.assertEqual(2, afreq("H"))
        self.assertEqual(3, afreq("I"))
        self.assertEqual(2, afreq("K"))
        self.assertEqual(6, afreq("L"))
        self.assertEqual(1, afreq("M"))
        self.assertEqual(2, afreq("N"))
        self.assertEqual(4, afreq("P"))
        self.assertEqual(2, afreq("Q"))
        self.assertEqual(6, afreq("R"))
        self.assertEqual(6, afreq("S"))
        self.assertEqual(4, afreq("T"))
        self.assertEqual(4, afreq("V"))
        self.assertEqual(1, afreq("W"))
        self.assertEqual(2, afreq("Y"))

    def test_cbase(self):
        self.assertEqual("T", cbase("A"))
        self.assertEqual("A", cbase("T"))
        self.assertEqual("G", cbase("C"))
        self.assertEqual("C", cbase("G"))

    def test_complement(self):
        self.assertEqual("TGCA", complement("ACGT"))

    def test_ctable(self):
        self.assertEqual("F", ctable("UUU"))
        self.assertEqual("L", ctable("CUU"))
        self.assertEqual("I", ctable("AUU"))
        self.assertEqual("V", ctable("GUU"))
        self.assertEqual("F", ctable("UUC"))
        self.assertEqual("L", ctable("CUC"))
        self.assertEqual("I", ctable("AUC"))
        self.assertEqual("V", ctable("GUC"))
        self.assertEqual("L", ctable("UUA"))
        self.assertEqual("L", ctable("CUA"))
        self.assertEqual("I", ctable("AUA"))
        self.assertEqual("V", ctable("GUA"))
        self.assertEqual("L", ctable("UUG"))
        self.assertEqual("L", ctable("CUG"))
        self.assertEqual("M", ctable("AUG"))
        self.assertEqual("V", ctable("GUG"))
        self.assertEqual("S", ctable("UCU"))
        self.assertEqual("P", ctable("CCU"))
        self.assertEqual("T", ctable("ACU"))
        self.assertEqual("A", ctable("GCU"))
        self.assertEqual("S", ctable("UCC"))
        self.assertEqual("P", ctable("CCC"))
        self.assertEqual("T", ctable("ACC"))
        self.assertEqual("A", ctable("GCC"))
        self.assertEqual("S", ctable("UCA"))
        self.assertEqual("P", ctable("CCA"))
        self.assertEqual("T", ctable("ACA"))
        self.assertEqual("A", ctable("GCA"))
        self.assertEqual("S", ctable("UCG"))
        self.assertEqual("P", ctable("CCG"))
        self.assertEqual("T", ctable("ACG"))
        self.assertEqual("A", ctable("GCG"))
        self.assertEqual("Y", ctable("UAU"))
        self.assertEqual("H", ctable("CAU"))
        self.assertEqual("N", ctable("AAU"))
        self.assertEqual("Y", ctable("UAC"))
        self.assertEqual("H", ctable("CAC"))
        self.assertEqual("N", ctable("AAC"))
        self.assertEqual("D", ctable("GAC"))
        self.assertEqual("", ctable("UAA"))
        self.assertEqual("Q", ctable("CAA"))
        self.assertEqual("K", ctable("AAA"))
        self.assertEqual("E", ctable("GAA"))
        self.assertEqual("", ctable("UAG"))
        self.assertEqual("Q", ctable("CAG"))
        self.assertEqual("K", ctable("AAG"))
        self.assertEqual("E", ctable("GAG"))
        self.assertEqual("C", ctable("UGU"))
        self.assertEqual("R", ctable("CGU"))
        self.assertEqual("S", ctable("AGU"))
        self.assertEqual("G", ctable("GGU"))
        self.assertEqual("C", ctable("UGC"))
        self.assertEqual("R", ctable("CGC"))
        self.assertEqual("S", ctable("AGC"))
        self.assertEqual("G", ctable("GGC"))
        self.assertEqual("", ctable("UGA"))
        self.assertEqual("R", ctable("CGA"))
        self.assertEqual("R", ctable("AGA"))
        self.assertEqual("G", ctable("GGA"))
        self.assertEqual("W", ctable("UGG"))
        self.assertEqual("R", ctable("CGG"))
        self.assertEqual("R", ctable("AGG"))
        self.assertEqual("G", ctable("GGG"))

    def test_delete(self):
        self.assertEqual("ACGT", delete("ACGTCCC", "CCC"))

    def test_is_dna(self):
        self.assertTrue(is_dna("ACGT"))

    def test_is_rna(self):
        self.assertTrue(is_rna("ACGU"))

    def test_is_protein(self):
        self.assertTrue(is_protein("ACDEFGHIKLMNPQRSTVWY"))

    def test_mass(self):
        self.assertEqual(2376.11432, mass("ACDEFGHIKLMNPQRSTVWY"))

    def test_mtable(self):
        self.assertEqual(71.03711, mass("A"))
        self.assertEqual(103.00919, mass("C"))
        self.assertEqual(115.02694, mass("D"))
        self.assertEqual(129.04259, mass("E"))
        self.assertEqual(147.06841, mass("F"))
        self.assertEqual(57.02146, mass("G"))
        self.assertEqual(137.05891, mass("H"))
        self.assertEqual(113.08406, mass("I"))
        self.assertEqual(128.09496, mass("K"))
        self.assertEqual(113.08406, mass("L"))
        self.assertEqual(131.04049, mass("M"))
        self.assertEqual(114.04293, mass("N"))
        self.assertEqual(97.05276, mass("P"))
        self.assertEqual(128.05858, mass("Q"))
        self.assertEqual(156.10111, mass("R"))
        self.assertEqual(87.03203, mass("S"))
        self.assertEqual(101.04768, mass("T"))
        self.assertEqual(99.06841, mass("V"))
        self.assertEqual(186.07931, mass("W"))
        self.assertEqual(163.06333, mass("Y"))

    def test_reverse(self):
        self.assertEqual("TGCA", reverse("ACGT"))

    def test_reverse_complement(self):
        self.assertEqual("ACGT", reverse_complement("ACGT"))

    def test_transcribe(self):
        self.assertEqual("U", transcribe("T"))

    def test_transcribe_back(self):
        self.assertEqual("T", transcribe_back("U"))

    def test_translate_dna(self):
        self.assertEqual("T", translate_dna("ACG"))

    def test_translate_rna(self):
        self.assertEqual("T", translate_rna("ACG"))
