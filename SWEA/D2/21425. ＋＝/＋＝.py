T = int(input())

for test_case in range(1, T + 1):
    a, b, n = map(int, input().split())

    if a > b:
        a, b = b, a

    count = 0

    while b <= n:
        a += b
        count += 1
        if a > b:
            a, b = b, a

    print(count)
