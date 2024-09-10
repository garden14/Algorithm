import sys

N = int(sys.stdin.readline().strip())
card = list(map(int, sys.stdin.readline().split()))

M = int(sys.stdin.readline().strip())
num = list(map(int, sys.stdin.readline().split()))
 
dic = {}

for i in card :
    if i in dic:
        dic[i] += 1
    else :
        dic[i] = 1

for i in num :
    if i in dic :
        print(dic[i], end = ' ')
    else :
        print(0, end = ' ')