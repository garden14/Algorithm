import sys

N = int(sys.stdin.readline().strip())
students = []

for _ in range(N) :
    x, y = map(int, sys.stdin.readline().split())
    students.append((x, y))

for i in students :
    rank = 1
    for j in students :
        if i[0] < j[0] and i[1] < j[1] :
            rank += 1
    print(rank, end=' ')