N = int(input())

cnt = 1
start = 1
rooms = 6

while N > start :
    start += rooms
    rooms += 6
    cnt += 1

print(cnt)