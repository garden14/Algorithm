import sys

T = int(sys.stdin.readline().strip())

for _ in range(T):
    n = int(sys.stdin.readline().strip())
    dic = {}
    for _ in range(n) :
        clothes, type = map(str, sys.stdin.readline().split())
        if type in dic :
            dic[type].append(clothes)
        else :
            dic[type] = [clothes]
    
    cnt = 1

    for i in dic :
        cnt *= (len(dic[i])+1)

    print(cnt-1)    
