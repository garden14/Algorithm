T = int(input())

for test_case in range(1, T + 1):
    a, b, c = map(int, input().split())
    result = 0

    if b >= c:
        result += b - c + 1
        b -= result
    if a >= b:
        result += a - b + 1
        a -= result
    if a < 1 or b < 1 or c < 1:
        result = -1

    print(f'#{test_case} {result}')
