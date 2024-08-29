N = input()
F = int(input())

standard = int(N[:-2] + '00')

while True:
    if standard % F == 0 :
        print(str(standard)[-2:])
        break
    else :
        standard += 1