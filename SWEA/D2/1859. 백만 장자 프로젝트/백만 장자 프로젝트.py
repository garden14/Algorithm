T = int(input())

for test_case in range(1, T + 1):
    N = int(input())
    pay = list(map(int, input().split()))

    max_price = 0
    result = 0

    for i in range(N - 1, -1, -1):
        if pay[i] > max_price :
            max_price = pay[i]
        else:
            result += max_price - pay[i]

    print(f'#{test_case} {result}')
