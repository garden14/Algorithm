import sys

T = int(sys.stdin.readline().strip())

for i in range(T) :
    n = int(sys.stdin.readline().strip())

    a, b = 1, 0
    for i in range(n) :
        a, b = b, a+b

    print(a, b)

