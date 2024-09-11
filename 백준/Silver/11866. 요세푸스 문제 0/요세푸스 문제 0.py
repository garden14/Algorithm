import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())
queue = deque()

for i in range(N) :
    queue.append(i+1)

print('<', end = '')
while queue :
    queue.rotate(-K)
    if len(queue) == 1 :
        print(queue.pop(), end = '')
    else : 
        print(queue.pop(), end= ', ')
print('>')