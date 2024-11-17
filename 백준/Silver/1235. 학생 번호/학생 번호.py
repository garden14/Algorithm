N = int(input())

nums = [input().strip() for _ in range(N)]

num_len = len(nums[0])
for k in range(1, num_len + 1):
    split_nums = [num[-k:] for num in nums]
    if len(set(split_nums)) == N:
        print(k)
        break