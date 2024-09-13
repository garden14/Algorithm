import sys

N = int(sys.stdin.readline().strip())
P = list(map(int,sys.stdin.readline().split()))

P.sort()

sum = 0
for i in range(len(P)) :
    sum += P[i] * (len(P) - i)

print(sum)