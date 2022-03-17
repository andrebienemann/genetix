from unittest import TestCase

from genetix.data import access_uniport


class TestData(TestCase):
    def test_access_uniport(self):
        protein = (
            ">sp|A2Z669|CSPLT_ORYSI CASP-like protein 5A2 OS=Oryza sativa subsp. indica OX=39946 GN=OsI_33147 PE=3 SV=1\n"
            "MRASRPVVHPVEAPPPAALAVAAAAVAVEAGVGAGGGAAAHGGENAQPRGVRMKDPPGAP\n"
            "GTPGGLGLRLVQAFFAAAALAVMASTDDFPSVSAFCYLVAAAILQCLWSLSLAVVDIYAL\n"
            "LVKRSLRNPQAVCIFTIGDGITGTLTLGAACASAGITVLIGNDLNICANNHCASFETATA\n"
            "MAFISWFALAPSCVLNFWSMASR\n"
        )
        self.assertEqual(protein, access_uniport("A2Z669"))
