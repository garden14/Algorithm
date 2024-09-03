import sys

def input() :
    return sys.stdin.readline().strip()

N = int(input())
strings = []

for _ in range(N) :
    strings.append(input())

strings = list(set(strings))
strings.sort()
strings.sort(key=len)

for string in strings :
    print(string)
