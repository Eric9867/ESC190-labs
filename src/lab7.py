
def partial_seam_energy(grid, seam_energy_grid, x, y):
    '''
    returns the sum of the tile's energy and the cumulative energy 
    of the lowest energy seam of the three directly above it
    Also stores the value for future lookup in seam_energy_grid
    '''
    if(seam_energy_grid[y][x] != None):
        return seam_energy_grid[y][x]

    if(y == 0):
        seam_energy_grid[y][x] = grid[y][x]
        return seam_energy_grid[y][x]

    # we calculate the cumulative seam energy of a tile using its own 
    # energy and the minimum seam energy of the tiles above it
    width = len(grid[0])
    seam_energy_grid[y][x] = grid[y][x] + min(
        seam_energy_grid[y-1][max(0, x - 1)],
        seam_energy_grid[y-1][x],
        seam_energy_grid[y-1][min(x + 1, width - 1)]
    )
    return seam_energy_grid[y][x]

def compute_seam_energies(grid):
    height = len(grid)
    width = len(grid[0])
    seam_energy_grid = [[None for i in range(width)] for j in range(height)]

    for j in range(height):
        for i in range(width):
            print(partial_seam_energy(grid, seam_energy_grid, i, j) == seam_energy_grid[j][i])
    
    return seam_energy_grid
    
def remove_min_seam(grid, seam_energy_grid):
    '''
    given a grid of partial seam energies for every tile, 
    trace the lowest-energy seam, starting from the bottom row

    remove this seam from the tile grid
    '''
    height = len(grid)
    width = len(grid[0])
    assert(height > 1) # can add proper handling of this case later 
    indices = [None for j in range(height)]
    indices[height - 1] = seam_energy_grid[height-1].index(min(seam_energy_grid[height - 1]))
    
    for j in range(height - 2, -1, -1):
        next_tiles = [float('inf'), float('inf'), float('inf')]
        i = indices[j + 1]
        if i > 0:
            next_tiles[0] = seam_energy_grid[j][i - 1]
        if i < width:
            next_tiles[2] = seam_energy_grid[j][i + 1]

        next_tiles[1] = seam_energy_grid[j][i]      
        
        # the indices in the next_tiles list correspond to i + 1,
        # where i is the value added to the index in the row directly
        # underneath
        indices[j] = i + next_tiles.index(min(next_tiles)) - 1
    
    # at this stage, we could just as easily return the list of indices
    for j, i in enumerate(indices):
        print(f'{j}.\t {grid[j].pop(i)}')


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

import numpy as np
if __name__ == '__main__':
    seam_energy_grid = compute_seam_energies(energies)
    print(np.array(energies))
    remove_min_seam(energies, seam_energy_grid)
    print(np.array(energies))