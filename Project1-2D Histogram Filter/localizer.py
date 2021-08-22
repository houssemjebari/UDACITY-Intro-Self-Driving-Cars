# import pdb
from helpers import normalize, blur

def initialize_beliefs(grid):
    height = len(grid)
    width = len(grid[0])
    area = height * width
    belief_per_cell = 1.0 / area
    beliefs = []
    for i in range(height):
        row = []
        for j in range(width):
            row.append(belief_per_cell)
        beliefs.append(row)
    return beliefs

def sense(color, grid, beliefs, p_hit, p_miss):
    new_beliefs = []
    beliefs_sum = 0
    for row,gr in zip(beliefs,grid):
        new_row = [(color == gr[i])*row[i]*p_hit+((1 - (color == gr[i]))*row[i]*p_miss) for i in range(len(row))]
        new_beliefs.append(new_row)
        beliefs_sum += sum(new_row)
    new_beliefs = [[j/beliefs_sum for j in i] for i in new_beliefs] 
    return new_beliefs

def move(dy, dx, beliefs, blurring):
    height = len(beliefs)
    width = len(beliefs[0])
    new_G = [[0.0 for i in range(width)] for j in range(height)]
    for i, row in enumerate(beliefs):
        for j, cell in enumerate(row):
            new_i = (i + dx ) % width
            new_j = (j + dy ) % height
            # pdb.set_trace()
            new_G[int(new_j)][int(new_i)] = cell
    return blur(new_G, blurring)