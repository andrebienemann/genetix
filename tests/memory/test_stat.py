from memory_profiler import profile

from genetix import stat


@profile
def run(cycles, size):
    for _ in cycles:
        stat.freq("ACGT")
        stat.gc_content("ACGT")
        stat.hamming_distance("ACGT", "ACGT")
        stat.titv_ratio("ACGT", "ACGT")


if __name__ == "__main__":
    size = 10**4
    cycles = range(size)
    run(cycles, size)
