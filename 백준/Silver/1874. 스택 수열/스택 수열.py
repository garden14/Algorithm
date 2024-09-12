import sys

n = int(sys.stdin.readline().strip())
stack, operation = [], []
count = 1 
result = True

for _ in range(n) :
    num = int(sys.stdin.readline().strip())

    while count <= num :
        stack.append(count)
        operation.append('+')
        count += 1
    
    if stack[-1] == num :
        stack.pop()
        operation.append('-')
    
    else :
        result = False
        break

if result == False :
    print('NO')
else :
    for op in operation :
        print(op)