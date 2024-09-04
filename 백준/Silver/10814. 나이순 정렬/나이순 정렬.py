import sys

N = int(sys.stdin.readline().strip())
members = []

for _ in range(N) :
    age, name = map(str, sys.stdin.readline().split())
    members.append((int(age),name))

members.sort(key=lambda x:x[0])

for i in range(N) :
    print(members[i][0], end= ' ')
    print(members[i][1])