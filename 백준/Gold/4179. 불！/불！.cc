#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
char miro[1001][1001];
int fire_dist[1001][1001];  // 불의 확산 시간 
int jihun_dist[1001][1001]; // 지훈이의 이동 시간 
int dr[] = {-1, 1, 0, 0}; // 상하좌우
int dc[] = {0, 0, -1, 1};

queue<pair<int, int>> fire;
queue<pair<int, int>> jihun;

void fire_bfs() {
    while (!fire.empty()) {
        int r = fire.front().first;
        int c = fire.front().second;
        fire.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue; 
            if (miro[nr][nc] == '#' || fire_dist[nr][nc] != -1) continue; // 벽이거나 이미 불이 번짐

            fire_dist[nr][nc] = fire_dist[r][c] + 1;
            fire.push({nr, nc});
        }
    }
}

int jihun_bfs() {
    while (!jihun.empty()) {
        int r = jihun.front().first;
        int c = jihun.front().second;
        jihun.pop();

        // 탈출 : 가장자리에 도달했는가
        if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
            return jihun_dist[r][c] + 1; // 시작이 0이었으므로 +1
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue; // 맵 밖
            if (miro[nr][nc] == '#' || jihun_dist[nr][nc] != -1) continue; // 벽이거나 이미 방문

            // 지훈이가 이동할 시간에 불이 아직 도달하지 않았는지 확인
            if (fire_dist[nr][nc] != -1 && jihun_dist[r][c] + 1 >= fire_dist[nr][nc]) {
                continue;
            }
            
            jihun_dist[nr][nc] = jihun_dist[r][c] + 1;
            jihun.push({nr, nc});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        fill(fire_dist[i], fire_dist[i] + C, -1);
        fill(jihun_dist[i], jihun_dist[i] + C, -1);
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> miro[i][j];
            if (miro[i][j] == 'F') {
                fire.push({i, j});
                fire_dist[i][j] = 0;
            } else if (miro[i][j] == 'J') {
                jihun.push({i, j});
                jihun_dist[i][j] = 0;
            }
        }
    }

    fire_bfs();
    
    int result = jihun_bfs();

    if (result == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << result;
    }

    return 0;
}