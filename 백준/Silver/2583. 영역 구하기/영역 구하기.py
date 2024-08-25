from collections import deque

M, N, K = map(int, input().split())
paper = [[0] * N for _ in range(M)]

for _ in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            paper[i][j] = 1

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    paper[x][y] = 1 
    area = 1  

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while queue:
        cur_x, cur_y = queue.popleft()

        for dx, dy in directions:
            nx, ny = cur_x + dx, cur_y + dy

            if 0 <= nx < M and 0 <= ny < N and paper[nx][ny] == 0:
                paper[nx][ny] = 1
                queue.append((nx, ny))
                area += 1

    return area

areas = []
for i in range(M):
    for j in range(N):
        if paper[i][j] == 0: 
            areas.append(bfs(i, j))

areas.sort()
print(len(areas))
print(' '.join(map(str, areas)))
