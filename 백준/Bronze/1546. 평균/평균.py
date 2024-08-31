N = int(input())
scores = list(map(int,input().split()))

M = max(scores)
sum = 0

for score in scores :
    sum += score / M * 100

print(sum / N)