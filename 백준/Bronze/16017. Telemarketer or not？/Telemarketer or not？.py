tel = []

for _ in range(4):
    tel.append(int(input()))


if tel[0] in (8, 9) and tel[3] in (8, 9) and tel[1] == tel[2]:
    print("ignore")
else : 
    print("answer")