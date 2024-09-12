import sys

K, N = map(int,sys.stdin.readline().split())
cables = []

for _ in range(K) :
    cables.append(int(sys.stdin.readline().strip()))

start = 1
end = max(cables)
result = 0 

while start <= end :
    mid = (start+end) // 2
    count = sum(cable // mid for cable in cables)

    if count >= N :
        result = mid
        start = mid + 1
    else :
        end = mid - 1

print(result)
