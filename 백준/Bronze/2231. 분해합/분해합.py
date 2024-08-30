N = int(input())
result = []

start = max(0, N - 9 * len(str(N)))

for i in range(start, N):
    ori = i
    sum = i
    
    while ori > 0 :
        sum += ori % 10
        ori //= 10
    
    if sum == N :
        result.append(i)
        break

if not result :
    print(0)
else :
    print(result[0])