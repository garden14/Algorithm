import sys
from collections import deque

N = int(sys.stdin.readline().strip())
dq = deque()

for _ in range(N) :
    command = sys.stdin.readline().strip()
    if command.startswith("push_back") :
        num = int(command[10:])
        dq.append(num)

    elif command.startswith("push_front") :
        num = int(command[11:])
        dq.appendleft(num)

    elif command.startswith("pop_front") :
        if len(dq) == 0 :
            print(-1)
        else :
            print(dq.popleft())

    elif command.startswith("pop_back") :
        if len(dq) == 0 :
            print(-1)
        else :
            print(dq.pop())

    elif command.startswith("size") :
        print(len(dq))

    elif command.startswith("empty") :
        if len(dq) == 0 :
            print(1)
        else : 
            print(0)
    
    elif command.startswith("front") :
        if len(dq) == 0 :
            print(-1)
        else :
            print(dq[0])
    
    elif command.startswith("back") :
        if len(dq) == 0 :
            print(-1)
        else :
            print(dq[-1])