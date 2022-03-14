def parse_fasta(fasta: str) -> tuple:
    """
    Given a string in a FASTA format returns a collection of tuples
    containing the sequence label and the sequence itself.

    Paramters
    fasta: a string in a FASTA format
    """
    data = list()
    entries = fasta.split(">")[1:]
    for entry in entries:
        lines = entry.split("\n")
        head, *tail = lines
        data.append((head, "".join(tail)))
    return data
