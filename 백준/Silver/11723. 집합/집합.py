import sys

M = int(sys.stdin.readline().strip())
S = set()

for _ in range(M) :
    command = sys.stdin.readline().strip()

    if 'add' in command :
        x = int(command[4:])
        S.add(x)
    elif 'remove' in command :
        x = int(command[7:])
        S.discard(x)
    elif 'check' in command :
        x = int(command[6:])
        if x in S :
            print(1)
        else : print(0)
    elif 'toggle' in command :
        x = int(command[7:])
        if x in S :
            S.remove(x)
        else :
            S.add(x)
    elif command == 'all' :
        S = set(range(1, 21))
    elif command == 'empty' :
        S = set()


