from collections import Counter
N = int(input())

family = []

for _ in range(N) :
    player = input()
    family.append(player[0])

cnt = Counter(family)

result = [key for key, value in cnt.items() if value >= 5]
    
if result:
    print("".join(sorted(result)))
else:
    print("PREDAJA")    