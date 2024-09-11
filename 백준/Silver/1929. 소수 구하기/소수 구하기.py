import sys

def check_prime(n) :
    for i in range(2,int(n**0.5)+1) :
        if n % i == 0 :
            return False
    return True

M, N = map(int, sys.stdin.readline().split())

for i in range (M,N+1) :
    if i == 1 :
        continue
    if check_prime(i) == True :
        print(i)