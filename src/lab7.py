energies = [[24,      22,      30,      15,      18,      19],
            [12,      23,      15,      23,      10,     15],
            [11,      13,      22,      13,      21,      14],
            [13,      15,      17,      28,      19,      21],
            [17,      17,      7,       27,      20,      19]]

# find the min energy starting at each col
# choose the min of 


def min_seam(node, row, col):
    #ill work on this later
    return min(min_seam(node[row-1][col-1]), min_seam(node[row-1][col]), min_seam(node[row-1][col+1]))