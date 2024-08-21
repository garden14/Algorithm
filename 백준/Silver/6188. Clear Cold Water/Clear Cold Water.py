from collections import deque, defaultdict

def find_pipe_distances():
    N, C = map(int, input().split())
    
    graph = defaultdict(list)
    
    for _ in range(C):
        E_i, B1_i, B2_i = map(int, input().split())
        graph[E_i].append(B1_i)
        graph[E_i].append(B2_i)
    
    distances = [-1] * (N + 1)
    queue = deque([1])
    distances[1] = 1
    
    while queue:
        current = queue.popleft()
        
        for neighbor in graph[current]:
            if distances[neighbor] == -1:  
                distances[neighbor] = distances[current] + 1
                queue.append(neighbor)
    
    for i in range(1, N + 1):
        if distances[i] != -1:
            print(distances[i])

find_pipe_distances()
