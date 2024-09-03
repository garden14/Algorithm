import sys

N = int(sys.stdin.readline().strip())
cnt = 0
endNumber = 666

while True :
    if '666' in str(endNumber) :
        cnt += 1
        if cnt == N :
            break
    endNumber += 1

print(endNumber)