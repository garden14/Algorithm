import sys

X = int(sys.stdin.readline().strip())
line = 1

while X > line :
    X -= line
    line += 1

if line % 2 != 0 :
    b = 1
    for _ in range(X-1):
        b += 1

else :
    b = line
    for _ in range(X-1):
        b -= 1
    
a = line + 1 - b 

print(f'{a}/{b}')
