N = int(input())
size = list(map(int, input().split()))
T, P = map(int, input().split())

cnt = 0
for s in size :
    if s == 0 :
        continue
    elif s <= T :
        cnt += 1
    elif s % T == 0:
        cnt += s // T
    else :
        cnt += s // T + 1

print(cnt)
print(N//P, N%P)