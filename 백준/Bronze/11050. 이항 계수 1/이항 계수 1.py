import sys
input = sys.stdin.readline

n, k = map(int, input().split())

def factorial(a) :
    if (a > 1) :
        return a * factorial(a-1)
    else :
        return 1

print(factorial(n) // (factorial(n-k) * factorial(k)))