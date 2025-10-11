#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[300][300];
bool visit[300][300];
int N, M;
int year = 0;

int dr[] = {-1,1,0,0}; // 상하좌우
int dc[] = {0,0,-1,1};

void bfs(int start_r, int start_c) {
    queue<pair<int ,int>> q;
    q.push({start_r, start_c});
    visit[start_r][start_c] = true;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            if(!visit[nr][nc] && map[nr][nc] > 0) {
                visit[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

void melt() {
    int temp_map[300][300] = {0}; 

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] > 0) { // 빙산이 있는 칸이라면
                int sea_count = 0;
                for (int k = 0; k < 4; ++k) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] == 0) {
                        sea_count++;
                    }
                }
                temp_map[i][j] = sea_count;
            }
        }
    }

    // 계산된 값을 바탕으로 실제 map에서 빙산 높이 줄이기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            map[i][j] -= temp_map[i][j];
            if (map[i][j] < 0) { 
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    while(true) {
        int chunk_count = 0;
        memset(visit, false, sizeof(visit));

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(map[i][j] > 0 && !visit[i][j]) {
                    bfs(i, j);
                    ++chunk_count;
                }
            }
        }

        if(chunk_count >= 2){
            cout << year << "\n";
            break;
        }

        if(chunk_count == 0) {
            cout << 0 << "\n";
            break;
        }

        melt();
        year++;
    }

    return 0;
}