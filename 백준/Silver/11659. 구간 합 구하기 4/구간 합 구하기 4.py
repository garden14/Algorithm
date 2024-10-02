import sys

n, m = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
temp = [0]
nSum = 0

for i in range(n) :
    nSum += nums[i]
    temp.append(nSum)

for _ in range(m) :
    start, end = map(int, sys.stdin.readline().split())
    print(temp[end] - temp[start-1])