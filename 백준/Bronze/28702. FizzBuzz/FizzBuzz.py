import sys

str = [sys.stdin.readline().strip() for _ in range(3)]

for i in range(2, -1, -1) :
    if str[i].isdigit() :
        n = int(str[i]) + (3-i)
        break

if n % 3 == 0 and n % 5 == 0 :
    print('FizzBuzz')
elif n % 3 == 0 :
    print('Fizz')
elif n % 5 == 0 :
    print('Buzz')
else :
    print(n)