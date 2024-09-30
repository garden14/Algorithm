import sys

N = int(sys.stdin.readline().strip())
connect = int(sys.stdin.readline().strip())
graph = [[] for i in range(N+1)]
visited = [0]*(N+1)


for _ in range(connect) :
    f, s = map(int, sys.stdin.readline().split())
    graph[f] += [s]
    graph[s] += [f]

def dfs(v) :
    visited[v] = True
    for i in graph[v] :
        if not visited[i] :
            dfs(i)

dfs(1)
print(sum(visited)-1)