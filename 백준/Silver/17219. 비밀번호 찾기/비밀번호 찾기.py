import sys

N, M = map(int, sys.stdin.readline().split())
sites = {}

for _ in range(N) :
    site, password = map(str, sys.stdin.readline().split())
    sites[site] = password

for _ in range(M) :
    site = sys.stdin.readline().strip()
    print(sites[site])