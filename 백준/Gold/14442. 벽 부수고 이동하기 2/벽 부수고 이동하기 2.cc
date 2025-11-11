#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M, K;
vector<string> map;

int dist[1000][1000][11]; // 벽을 k번 부수고 도달한 최단 거리
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int bfs() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++ j) {
            for(int l = 0; l <= K; ++l) {
                dist[i][j][l] = -1;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({0,0,0});
    dist[0][0][0] = 1;

    while(!q.empty()) {
        auto [r, c, k] = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            if(map[nr][nc] == '0' && dist[nr][nc][k] == -1) {
                dist[nr][nc][k] = dist[r][c][k] + 1;
                q.push({nr, nc, k});
            }

            else if (map[nr][nc] == '1' && k < K && dist[nr][nc][k + 1] == -1) {
                dist[nr][nc][k + 1] = dist[r][c][k] + 1;
                q.push({nr, nc, k + 1});

            }
        }
    }

    int min_dist = -1;
    for(int i = 0; i <= K; ++i) {
        int d = dist[N-1][M-1][i];
        if(d != -1) {
            if(min_dist == -1 || d < min_dist) {
                min_dist = d;
            }
        }
    }

    return min_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    map.resize(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> map[i];
    }

    cout << bfs() << "\n";

    return 0;
}