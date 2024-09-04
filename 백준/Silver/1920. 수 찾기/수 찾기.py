import sys

N = int(sys.stdin.readline().strip())
A = set(map(int, sys.stdin.readline().strip().split()))

M = int(sys.stdin.readline().strip())
B = list(map(int, sys.stdin.readline().strip().split()))

for m in B :
    print(1) if m in A else print(0)