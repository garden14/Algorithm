import sys

t = int(sys.stdin.readline())

for _ in range(t) :
    k = int(sys.stdin.readline())
    n = int(sys.stdin.readline())

    f = [i for i in range(1, n+1)] # 0층

    for i in range (1, k+1) :
        for j in range(1,n) :
            f[j] += f[j-1]
    
    print(f[n-1])