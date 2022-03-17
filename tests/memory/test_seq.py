from memory_profiler import profile

from genetix import seq


@profile
def run(cycles, size):
    for _ in cycles:
        seq.afreq("A")
        seq.all_contain(["ACU", "AU", "ACU"], "A")
        seq.cbase("A")
        seq.complement("ACT")
        seq.ctable("ACC")
        seq.delete("ACU", "U")
        seq.is_dna("ACGT")
        seq.is_rna("ACGU")
        seq.mass("ACD")
        seq.mtable("A")
        seq.reverse("ACG")
        seq.reverse_complement("ACG")
        seq.shortest_seq(["ACU", "AU", "ACU"])
        seq.transcribe("ACG")
        seq.transcribe_back("ACG")
        seq.translate_dna("ACT")
        seq.translate_rna("ACU")


if __name__ == "__main__":
    size = 10**4
    cycles = range(size)
    run(cycles, size)
