#swapping row1 with row2
def swap_row(matrix,row1,row2):
    temp_row = matrix[row1]
    matrix[row1] = matrix[row2]
    matrix[row2] = temp_row
    return matrix

#multiply one row by a coefficient
def row_multiply(matrix,row,coefficient):
    for i in range(0,len(matrix[row])):
        matrix[row][i] = matrix[row][i]*coefficient
    return matrix

#reduce all rows based on base_row in the (col+1)-th column, base_row must have 1 in (col+1)th column
def row_reduce(matrix,base_row,col):
    for i in range(base_row+1,len(matrix),1):
        multiplier = matrix[i][col]
        for n in range(0,len(matrix[0]),1):
            subtract = matrix[base_row][n]*multiplier
            matrix[i][n] = matrix[i][n]-subtract
    return matrix

def row_reverse_reduce(matrix,base_row,col):
    for i in range(0,base_row,1):
        multiplier = matrix[i][col]
        for n in range(0, len(matrix[0]), 1):
            subtract = matrix[base_row][n] * multiplier
            matrix[i][n] = matrix[i][n] - subtract
    return matrix


def ge_fw(matrix):
    [row,col] = [len(matrix),len(matrix[0])]
    current_col = 0
    current_row = 0
    while current_col <col and current_row < row:
        max_entry = matrix[current_row][current_col]
        max_row = current_row
        for r in range(current_row+1,row):
            if abs(matrix[r][current_col])>abs(max_entry):
                max_entry = matrix[r][current_col]
                max_row = r
        if max_entry != 0:
            matrix = swap_row(matrix,max_row,current_row)
            multiplier = 1.0/max_entry
            matrix = row_multiply(matrix,current_row,multiplier)
            matrix = row_reduce(matrix,current_row,current_col)
            current_col += 1
            current_row += 1
        else:
            current_col+=1
    return matrix


def ge_bw(matrix):
    [row, col] = [len(matrix), len(matrix[0])]
    for r in reversed(range(1,row,1)):
        for c in range(1,col,1):
            if matrix[r][c] == 1:
                matrix = row_reverse_reduce(matrix,r,c)
                break
    return matrix

