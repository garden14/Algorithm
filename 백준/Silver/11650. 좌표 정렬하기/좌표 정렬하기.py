import sys

N = int(sys.stdin.readline().strip())
coor = []

for _ in range(N) :
    x, y = map(int, sys.stdin.readline().split())
    coor.append((x, y))

coor.sort(key=lambda x : (x[0], x[1]))

for i in range(N) :
    print(coor[i][0], end= ' ')
    print(coor[i][1])