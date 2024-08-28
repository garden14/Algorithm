T = int(input())

test = []

for _ in range(T) :
    test.append(int(input()))

for num in test :
    str_sq = str(num * num)
    str_num = str(num)

    if str_sq[-len(str_num):] == str_num :
        print("YES")
    else :
        print("NO")