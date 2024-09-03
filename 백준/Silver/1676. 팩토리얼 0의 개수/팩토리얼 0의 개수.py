import sys

N = int(sys.stdin.readline().strip())
factorial = 1

for i in range (1,N+1) :
    factorial *= i

factorial = list(map(int,str(factorial)))
factorial.reverse()
cnt = 0

for n in factorial :
    if n == 0 :
        cnt += 1
    if cnt != 0 and n != 0 :
        break

print(cnt)