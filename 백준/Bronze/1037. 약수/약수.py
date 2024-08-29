N = int(input())
num_input = input()

nums = [int(num) for num in num_input.split()]


min_num = min(nums)
max_num = max(nums)
original = min_num * max_num

if original in nums:
    print(original * 2)
else:
    print(original)