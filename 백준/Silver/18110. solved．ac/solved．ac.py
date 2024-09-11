import sys

def f_round(n) :
    if n - int(n) < 0.5 :
        return int(n)
    else :
        return int(n)+1

n = int(sys.stdin.readline().strip())

if n == 0 :
    print(0)
else :
    opinion = []
    for _ in range(n) :
        opinion.append(int(sys.stdin.readline().strip()))

    opinion.sort()
    trimmed_mean = f_round(n * 0.15)

    opinion = opinion[trimmed_mean:n-trimmed_mean]

    print(f_round(sum(opinion)/len(opinion)))
