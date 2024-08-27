A, B = map(int, input().split())

cnt = 3

A -= 2
B -= 1

C = min(A,B)

cnt += (2*C)

print(cnt)