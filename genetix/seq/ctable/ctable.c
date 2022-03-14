char _ctable[4][4][4] = {{
                             {'K', 'N', 'N', 'K'},
                             {'T', 'T', 'T', 'T'},
                             {'I', 'I', 'I', 'M'},
                             {'R', 'S', 'S', 'R'},
                         },
                         {
                             {'Q', 'H', 'H', 'Q'},
                             {'P', 'P', 'P', 'P'},
                             {'L', 'L', 'L', 'L'},
                             {'R', 'R', 'R', 'R'},
                         },
                         {
                             {'\0', 'Y', 'Y', '\0'},
                             {'S', 'S', 'S', 'S'},
                             {'L', 'F', 'F', 'L'},
                             {'\0', 'C', 'C', 'W'},
                         },
                         {
                             {'E', 'D', 'D', 'E'},
                             {'A', 'A', 'A', 'A'},
                             {'V', 'V', 'V', 'V'},
                             {'G', 'G', 'G', 'G'},
                         }};

int _hash(char c) { return ((int)c - 65) % 8 / 2; }

char ctable(char *seq) {
    int c0 = _hash(seq[0]);
    int c1 = _hash(seq[1]);
    int c2 = _hash(seq[2]);
    return _ctable[c0][c1][c2];
}
