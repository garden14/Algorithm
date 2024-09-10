from collections import deque
import sys

N = int(sys.stdin.readline().strip())
queue = deque()

for _ in range(N) :
    command = sys.stdin.readline().strip()

    if 'push' in command :
        command = int(command[5:])
        queue.append(command)
    
    elif command == 'pop' :
        if len(queue) == 0 :
            print(-1)
        else :
            print(queue.popleft())

    elif command == 'size' :
        print(len(queue))
    
    elif command == 'empty' :
        if len(queue) == 0 :
            print(1)
        else :
            print(0)
    
    elif command == 'front' :
        if len(queue) == 0 :
            print(-1)
        else :
            print(queue[0])
    
    elif command == 'back' :
        if len(queue) == 0 :
            print(-1)
        else : 
            print(queue[-1])      
        
