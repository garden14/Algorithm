from itertools import combinations
import math

def lcm(a, b):
    return a * b // math.gcd(a, b)

numbers = list(map(int, input().split()))

min_lcm = float('inf')  
for comb in combinations(numbers, 3):
    a, b, c = comb
    current_lcm = lcm(lcm(a, b), c)
    if current_lcm < min_lcm:
        min_lcm = current_lcm

print(min_lcm)