import sys

K = int(sys.stdin.readline().strip())
stack = []

for _ in range(K) :
    num = int(sys.stdin.readline().strip())
    if num == 0 :
        stack.pop()
    else :
        stack.append(num)
    
print(sum(stack))