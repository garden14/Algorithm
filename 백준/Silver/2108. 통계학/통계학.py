import sys

N = int(sys.stdin.readline().strip())
nums = []

for _ in range(N) :
    nums.append(int(sys.stdin.readline().strip()))

nums.sort()

print(round(sum(nums)/N))
print(nums[N//2])

counts = dict()

for n in nums:
    if n in counts:
        counts[n] = counts[n] + 1
    else :
        counts[n] = 1

mode = max(counts.values())
mode_list = []

for i in counts :
    if mode == counts[i] :
        mode_list.append(i)

if len(mode_list) > 1 :
    print(mode_list[1])
else :
    print(mode_list[0])


print(nums[-1]-nums[0])