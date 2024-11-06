T = 10

for test_case in range(1, T + 1):
    N = int(input())
    building = list(map(int, input().split()))

    result = 0

    for i in range(2, N-2):
        compare = building[i-2:i+3]
        compare_s = list(compare)
        compare_s.sort(reverse=True)
        if compare[2] == compare_s[0]:
            result += compare_s[0] - compare_s[1]

    print(f'#{test_case} {result}')