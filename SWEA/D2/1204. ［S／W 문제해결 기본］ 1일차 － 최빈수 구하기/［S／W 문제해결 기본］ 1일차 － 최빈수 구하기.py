from collections import Counter

T = int(input())

for test_case in range(1, T + 1):
    test_num = int(input())
    score = list(map(int, input().split()))

    count_score = Counter(score)
    max_common = max(count_score.values())

    result = max([num for num, freq in count_score.items() if freq == max_common])

    print(f'#{test_num} {result}')
