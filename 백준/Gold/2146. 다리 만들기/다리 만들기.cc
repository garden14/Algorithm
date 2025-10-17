#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N;
int min_bridge_len = 2e9;
int map[100][100];
bool visit[100][100];
int dist[100][100]; // 다리 길이를 측정

int dr[] = {-1,1,0,0}; // 상하좌우
int dc[] = {0,0,-1,1};

void numbering_bfs(int row, int col, int island_num) {
    // 섬을 구분해야 한다
    queue<pair<int, int>> q;
    q.push({row, col});
    visit[row][col] = 1;
    map[row][col] = island_num;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc]) continue;
            
            if(map[nr][nc] == 1) {
                visit[nr][nc] = 1;
                map[nr][nc] = island_num;
                q.push({nr, nc});
            }          
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    memset(visit, 0, sizeof(visit));

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    int island_num = 2; // 섬 번호는 2부터 시작
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(map[i][j] == 1 && !visit[i][j]) {
                numbering_bfs(i, j, island_num++);
            }
        }
    }

    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j] != 0) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (dist[r][c] >= min_bridge_len) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

            // 다른 섬과 만났을 때
            if (map[nr][nc] != 0 && map[nr][nc] != map[r][c]) {
                min_bridge_len = min(min_bridge_len, dist[r][c] + dist[nr][nc]);
            }

            // 바다를 만났을 때 (아직 방문하지 않은)
            if (map[nr][nc] == 0) {
                map[nr][nc] = map[r][c]; // 내 섬 번호로 영역 확장
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    cout << min_bridge_len << "\n";
    
    return 0;
}

// 섬은 동서남북으로 육지가 붙어있는 덩어리
// 다리는 하나만, 가장 짧게
// 바다에 가장 짧은 다리를 놓아 두 대륙을 연결
// 먼저 bfs로 섬인지 바다인지 구분해야 한다 
// 각 섬의 해안가에서 동시에 바다 쪽으로 한 칸씩 확장해야 한다
// 해안가 : 자신은 땅이지만 상하좌우에 하나라도 0이 존재하는 칸
