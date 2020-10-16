# Sudoku Solver using Python (Backtracking)

board = [
    [7,8,0,4,0,0,1,2,0],
    [6,0,0,0,7,5,0,0,9],
    [0,0,0,6,0,1,0,7,8],
    [0,0,7,0,4,0,2,6,0],
    [0,0,1,0,5,0,9,3,0],
    [9,0,4,0,6,0,0,0,5],
    [0,7,0,3,0,0,0,1,2],
    [1,2,0,0,0,7,4,0,0],
    [0,4,9,2,0,6,0,0,7]
]

def solve(board):

    find = find_empty(board)
    if not find:
        return True
    else:
        row, col = find

    for i in range(1, 10):
        if valid(board, i, (row, col)):
            board[row][col] = i

            if solve(board):
                return True
            
            board[row][col] = 0

    return False


def valid(board, num, pos):

    # Check row
    for i in range(len(board)):
        if board[pos[0]][i] == num and pos[1] != 1:
            return False
    
    # Check column
    for i in range(len(board)):
        if board[i][pos[1]] == num and pos[0] != i:
            return False

    # Check Box 
    box_x = pos[1] // 3
    box_y = pos[0] // 3

    for i in range(box_y * 3, box_y * 3 + 3):
        for j in range(box_x * 3, box_x * 3 + 3):
            if board[i][j] == num and (i, j) != pos:
                return False
    
    return True



def print_board(board):

    for i in range(len(board)):
        if i % 3 == 0 and i != 0:
            print("- - - - - - - - - - - -")
        
        for j in range(len(board[0])):
            if j % 3 == 0 and j != 0:
                print(" | ", end = "")
            
            if j == 8:
                print(board[i][j])
            else:
                print(str(board[i][j]) + " ", end = "")
                
def find_empty(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                return (i, j)   # row, column

# To see the question board and solved board

print_board(board)
solve(board)
print("-----------------------")
print_board(board)


'''
7 8 0  | 4 0 0  | 1 2 0
6 0 0  | 0 7 5  | 0 0 9
0 0 0  | 6 0 1  | 0 7 8
- - - - - - - - - - - -
0 0 7  | 0 4 0  | 2 6 0
0 0 1  | 0 5 0  | 9 3 0
9 0 4  | 0 6 0  | 0 0 5
- - - - - - - - - - - -
0 7 0  | 3 0 0  | 0 1 2
1 2 0  | 0 0 7  | 4 0 0
0 4 9  | 2 0 6  | 0 0 7
-----------------------
7 8 5  | 4 3 9  | 1 2 6
6 1 2  | 8 7 5  | 3 4 9
4 9 3  | 6 2 1  | 5 7 8
- - - - - - - - - - - -
8 5 7  | 9 4 3  | 2 6 1
2 3 1  | 7 5 8  | 9 3 4
9 6 4  | 1 6 2  | 7 8 5
- - - - - - - - - - - -
5 7 8  | 3 9 4  | 6 1 2
1 2 6  | 5 8 7  | 4 9 3
3 4 9  | 2 1 6  | 8 5 7
'''
