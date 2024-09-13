import sys

N, M = map(int,sys.stdin.readline().split())
people = {}
result = []

for _ in range(N) :
    person = sys.stdin.readline().strip()
    people[person] = 'listen'

for _ in range(M) :
    person = sys.stdin.readline().strip()
    if person in people :
        result.append(person)

result.sort()

print(len(result))
for i in result :
    print(i)
   