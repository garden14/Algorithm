import sys
from collections import deque

T = int(sys.stdin.readline().strip())

for _ in range(T) :
    N, M = map(int,sys.stdin.readline().split())
    priority = deque(map(int,sys.stdin.readline().split()))
    queue = deque((idx, p) for idx, p in enumerate(priority))

    count = 0

    while queue :
        current = queue.popleft()
        if any(current[1] < q[1] for q in queue) :
            queue.append(current)
        else :
            count += 1
            if current[0] == M :
                print(count)
                break

