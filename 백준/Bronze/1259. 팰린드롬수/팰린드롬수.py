str = []

while True :
    s = input()
    if s == '0' : break
    else : str.append(s.lstrip('0'))

for s in str :
    if s == s[::-1]:
        print("yes")
    else : print("no")