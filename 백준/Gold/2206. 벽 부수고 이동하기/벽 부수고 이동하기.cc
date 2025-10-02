#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<vector<int>>> visit;

int dr[] = {-1,1,0,0}; // 상하좌우
int dc[] = {0,0,-1,1};

struct STATE{
    int r, c;
    int broken; // 0 : 벽 안 부숨 / 1: 벽 부숨
};


int bfs() {
    queue<STATE> q;
    q.push({1, 1, 0});
    visit[1][1][0] = 1;

    while(!q.empty()) {
        STATE current = q.front();
        q.pop();
        int r = current.r;
        int c = current.c;
        int broken = current.broken;

        if(r == N && c == M) {
            return visit[r][c][broken];
        }

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 만약 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면 한개까지는 부수는 것 허용

            if(nr < 1 || nr > N || nc < 1 || nc > M) continue;

            if(grid[nr][nc] == 0 && visit[nr][nc][broken] == 0){
                visit[nr][nc][broken] = visit[r][c][broken] + 1;
                q.push({nr,nc,broken});
            }
            else if (grid[nr][nc] == 1 && broken == 0) {
                if(visit[nr][nc][1] == 0) {
                    visit[nr][nc][1] = visit[r][c][broken] + 1;
                    q.push({nr, nc, 1});
                }
            }
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    grid.resize(N + 1,vector<int>(M + 1));
    visit.resize(N + 1, vector<vector<int>>(M + 1, vector<int>(2, 0)));

    for(int r = 1; r <= N; ++r) {
        string str;
        cin >> str;
        for(int c = 1; c <= M; ++c) {
            grid[r][c] = str[c - 1] - '0';
        }
    }
    
    cout << bfs() << "\n";

    return 0;
}