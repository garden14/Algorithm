import sys

def balance_check(line) :
    stack = []
    for s in line :
        if s == '[' or s == '(' :
            stack.append(s)
        elif s == ']' :
            if len(stack) != 0 and stack[-1] == '[' :
                stack.pop()
            else :
                stack.append(']')
                break
        elif s == ')' :
            if len(stack) != 0 and stack[-1] == '(' :
                stack.pop()
            else :
                stack.append(')')
                break           
    if len(stack) == 0 :
        return 'yes'
    else :
        return 'no' 



while True :
    line = sys.stdin.readline().rstrip()
    if line == '.' :
        break
    print(balance_check(line))