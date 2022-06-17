import sys
N, M = map(int, input().split())
chess_board = []
for i in range(N):
    chess_board.append((sys.stdin.readline()).rstrip())


def calc_recolored_tile_number(row, col):
    recolored_tile_number = 0
    left_head = chess_board[row][col]
    for i in range(row, row + 8):
        for j in range(col, col + 8):
            if(i % 2 == row % 2):
                if(j % 2 == col % 2):
                    if(chess_board[i][j] != left_head):
                        recolored_tile_number += 1
                else:
                    if(chess_board[i][j] == left_head):
                        recolored_tile_number += 1
            else:
                if(j % 2 == col % 2):
                    if(chess_board[i][j] == left_head):
                        recolored_tile_number += 1
                else:
                    if(chess_board[i][j] != left_head):
                        recolored_tile_number += 1
    if(recolored_tile_number > 32):
        recolored_tile_number = 64 - recolored_tile_number
    return recolored_tile_number


min_recolored_tile = 8 * 8

for row in range(N - 7):
    for col in range(M - 7):
        current_recolored_tile_number = calc_recolored_tile_number(row, col)
        if(current_recolored_tile_number <= min_recolored_tile):
            min_recolored_tile = current_recolored_tile_number
print(min_recolored_tile)
