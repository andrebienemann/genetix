from unittest import TestCase

from genetix.stat import freq, gc_content, hamming_distance, titv_ratio


class TestStat(TestCase):
    def test_get_freq(self):
        self.assertDictEqual({"A": 1, "C": 1, "G": 1, "T": 1}, freq("ACGT"))

    def test_get_gc_content(self):
        self.assertEqual(50.0, gc_content("ACGT"))

    def test_get_hamming_distance(self):
        self.assertEqual(4, hamming_distance("ACGT", "TGCA"))

    def test_get_tt_ratio(self):
        self.assertEqual(0.0, titv_ratio("ACGT", "GTAC"))
