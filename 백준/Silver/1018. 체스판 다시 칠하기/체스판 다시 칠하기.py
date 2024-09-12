import sys

N, M = map(int, sys.stdin.readline().split())
board, answer = [], []

for _ in range(N) :
    board.append(sys.stdin.readline().strip())

for i in range(N-7) :
    for j in range(M-7) :
        black = 0

        for x in range(i, i+8) :
            for y in range(j, j+8) :
                if (x+y) % 2 == 0 :
                    if board[x][y] == 'W' :
                        black += 1
                else :
                    if board[x][y] == 'B' :
                        black += 1
        answer.append(black)
        answer.append(64-black)

print(min(answer))