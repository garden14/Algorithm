#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int paper[100][100];
bool visit[100][100];
int cheese_cnt = 0;
int time_cnt = 0;
int dr[] = {-1,1,0,0}; // 상하좌우
int dc[] = {0,0,-1,1};

void bfs() {
    memset(visit, false, sizeof(visit));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = true;
    
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            if(!visit[nr][nc] && paper[nr][nc] == 0) {
                visit[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

void solution() {
    while(cheese_cnt > 0) {
        ++time_cnt;

        bfs();

        vector<pair<int, int>> to_melt;

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(paper[i][j] == 1) {
                    int contact_cnt = 0;
                    for(int k = 0; k < 4; ++k) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if(visit[ni][nj]) ++contact_cnt;
                    }

                    if(contact_cnt >= 2) to_melt.push_back({i, j});
                }
            }
        }

        for(auto pos : to_melt) {
            paper[pos.first][pos.second] = 0;
            --cheese_cnt;
        }

    }

}


// 4변 중에서 적어도 2변 이상이 공기 접촉 -> 한시간 뒤 X
// 치즈 내부 공간은 외부와 접촉하지 않는 것으로 가정
// 치즈가 모두 녹아 없어지는 데 걸리는 시간 출력

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> paper[i][j];
            if(paper[i][j] == 1) {
                ++cheese_cnt;
            }
        }
    }

    solution();
    cout << time_cnt << "\n";

    return 0;
}