from unittest import TestCase

from genetix.parse import parse_fasta


class TestParse(TestCase):
    def test_parse_fasta(self):
        raw_label = (
            ">sp|Q0TMT1|RL13_CLOP1 50S ribosomal protein L13 OS=Clostridium perfringens "
            "(strain ATCC 13124 / DSM 756 / JCM 1290 / NCIMB 6125 / NCTC 8237 / Type A)"
            " OX=195103 GN=rplM PE=3 SV=1\n"
        )
        raw_seq = (
            "MKSYIAKAQEVERKWYVVDAAGKPLGRVASQVASILRGKNKPTFTPNVDCGDFVIVINAE\n"
            "KVVLTGKKLDQKMLRKHSLYAGGLKETPYREVLEKKPEFAFEEAVRRMLPTGVLGRKMLK\n"
            "KLNVYRGAEHDHAAQKPEVLELRY\n"
        )
        fasta = raw_label + raw_seq
        entries = parse_fasta(fasta)
        label, seq = entries[0]
        self.assertEqual(raw_label.replace("\n", "")[1:], label)
        self.assertEqual(raw_seq.replace("\n", ""), seq)
