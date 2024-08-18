from collections import deque

def solution(priorities, location):
    answer = 0
    queue = deque((idx,i) for idx, i in enumerate(priorities))
    
    while True:
        current = queue.popleft()
        if any(current[1] < q[1] for q in queue):
            queue.append(current)
        else:
            answer += 1
            if current[0] == location:
                return answer
