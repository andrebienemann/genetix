from urllib.request import urlopen


def access_uniport(prot_id: str) -> str:
    """
    Given a protein id, queries the uniport API
    and returns the corresponding protein string

    Parameters
    prot_id: the protein id to query for
    """
    response = urlopen(f"http://www.uniprot.org/uniprot/{prot_id}.fasta")
    return "".join([line.decode("utf-8") for line in response])
