N = int(input())
origin = N
cnt = 0

while True :
    a = origin // 10
    b = origin % 10
    c = (a+b) % 10
    origin = (b*10) + c

    cnt += 1
    if (origin == N) :
        break

print(cnt)