N, new_score, P = map(int, input().split())

if N == 0:
    print(1)
else:
    scores = list(map(int, input().split()))
    if N == P and scores[-1] >= new_score:
        print(-1)
    else:
        rank = N+1
        for i in range(N) :
            if scores[i] <= new_score:
                rank = i+1
                break
        print(rank)