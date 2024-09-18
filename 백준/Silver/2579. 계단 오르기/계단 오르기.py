import sys

n = int(sys.stdin.readline().strip())
score = []
dp = []

for _ in range(n) :
    score.append(int(sys.stdin.readline().strip()))

if len(score) < 3 :
    print(sum(score))
else :
    dp.append(score[0])
    dp.append(max(score[0]+score[1], score[1]))
    dp.append(max(score[0] + score[2], score[1] + score[2]))

    for i in range(3, n):
        dp.append(max(dp[i-3] + score[i-1] + score[i], dp[i-2] + score[i]))

    print(dp.pop())