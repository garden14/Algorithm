from itertools import *

N, M = map(int, input().split())
num = list(map(int, input().split()))

numList = list(combinations(num,3))
sumList = list(sum(tup) for tup in numList)

maxSum = 0
for sum in sumList :
    if sum <= M :
        maxSum = max(maxSum, sum)

print(maxSum)