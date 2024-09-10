import sys

def determine_VPS(line):
    stack = []
    for s in line :
        if s == '(' :
            stack.append(s)
        elif s == ')' :
            if len(stack) != 0 and stack[-1] == '(' :
                stack.pop()
            else :
                stack.append(s)
                break
    if len(stack) != 0 :
        return 'NO'
    else : return 'YES'


T = int(sys.stdin.readline().strip())

for i in range(T) :
    line = sys.stdin.readline().strip()
    print(determine_VPS(line))
