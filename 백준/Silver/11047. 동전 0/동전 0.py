import sys

N, K = map(int, sys.stdin.readline().split())
coin = []

for _ in range(N) :
    coin.append(int(sys.stdin.readline().strip()))

coin.sort(reverse=True)

count = 0

for c in coin :
    count += K // c
    K %= c

print(count)
