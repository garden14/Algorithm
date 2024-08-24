import sys
sys.setrecursionlimit(10000) 

def dfs(x, y):
    stack = [(x, y)]
    while stack:
        x, y = stack.pop()
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < H and 0 <= ny < W and grid[nx][ny] == '#':
                grid[nx][ny] = '.'
                stack.append((nx, ny))

T = int(input())

for _ in range(T):
    H, W = map(int, input().split())
    grid = [list(input().strip()) for _ in range(H)]
    
    flock_count = 0
    
    for i in range(H):
        for j in range(W):
            if grid[i][j] == '#':
                dfs(i, j)
                flock_count += 1
    
    print(flock_count)
