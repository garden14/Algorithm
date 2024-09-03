import sys

N = int(sys.stdin.readline().strip())
nums = [int(sys.stdin.readline().strip()) for _ in range(N)]
nums.sort()

for n in nums :
    print(n)