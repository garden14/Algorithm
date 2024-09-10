import sys

stack = []

def s_push(X) :
    stack.append(X)

def s_pop() :
    if len(stack) == 0 :
        return -1
    else :
        return stack.pop()

def s_size() :
    return len(stack)

def s_empty() :
    if len(stack) == 0 :
        return 1
    else :
        return 0

def s_top() :
    if len(stack) == 0 :
        return -1
    else :
        return stack[-1]


N = int(sys.stdin.readline().strip())

for _ in range(N) :
    command = sys.stdin.readline().strip()
    
    if 'push' in command :
        command = int(command[5:])
        s_push(command)

    elif command == 'pop' :
        print(s_pop())

    elif command == 'size' :
        print(s_size())

    elif command == 'empty' :
        print(s_empty())

    elif command == 'top' :
        print(s_top())