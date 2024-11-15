import sys

N = int(sys.stdin.readline().strip())
heights = list(map(int,sys.stdin.readline().split()))

result = [0] * N 

for i in range(1, N+1) :
    count = heights[i-1]
    for j in range(N) :
        if result[j] == 0:
            if count == 0 :
                result[j] = i
                break
            count -= 1

print(*result)