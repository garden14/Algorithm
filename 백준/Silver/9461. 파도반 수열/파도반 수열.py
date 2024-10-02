import sys

T = int(sys.stdin.readline().strip())

for _ in range(T) :
    n = int(sys.stdin.readline().strip())

    dp = [1] * (n+1)

    for i in range(1, n+1) :
        if 0 < i < 4  :
            dp[i] = 1
        else :
            dp[i] = dp[i-2] + dp[i-3]
    
    print(dp[n])

    