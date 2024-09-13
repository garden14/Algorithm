import sys

N, M = map(int,sys.stdin.readline().split())
pocketmon1 = {}
pocketmon2 = {}

for i in range(N) :
    name = sys.stdin.readline().strip()
    pocketmon1[i+1] = name
    pocketmon2[name] = i+1


for _ in range(M) :
    q = sys.stdin.readline().strip()
    
    if q.isdigit() :
        print(pocketmon1[int(q)])
    else :
        print(pocketmon2[q])
