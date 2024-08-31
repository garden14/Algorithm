L = int(input())
str = list(input())

result = 0

for i in range(L) :
    result += (ord(str[i])-96) * (31**i)
    result %= 1234567891

print(result)
