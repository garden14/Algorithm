#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int min_total_time = 2e9;
int empty_cell_count = 0;
vector<vector<int>> grid;
vector<pair<int, int>> virus_loc;
vector<pair<int, int>> active_virus;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

void bfs() {
    int infected_empty_cells = 0; 
    int max_dist = 0;         

    vector<vector<int>> dist(N, vector<int>(N, -1)) ;
    queue<pair<int, int>> q;
    for(int i = 0; i < M; ++i) {
        q.push(active_virus[i]);
        int r = active_virus[i].first;
        int c = active_virus[i].second;
        dist[r][c] = 0;
    }

    while(!q.empty()) {
        auto current = q.front();
        int curr_r = current.first;
        int curr_c = current.second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = curr_r + dr[i];
            int nc = curr_c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N || grid[nr][nc] == 1 || dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[curr_r][curr_c] + 1;
            q.push({nr, nc});

            if (grid[nr][nc] == 0) {
                infected_empty_cells++;
                max_dist = max(max_dist, dist[nr][nc]);
            }
        }
    }

    // 모든 빈 칸을 감염시켰는지 확인
    if (infected_empty_cells == empty_cell_count) {
        min_total_time = min(min_total_time, max_dist);
    }
}

void combination(int count, int start_idx) {
    if(count == M){
        bfs();
        return;
    }

    for(int i = start_idx; i < virus_loc.size(); ++i) {
        active_virus.push_back(virus_loc[i]);
        combination(count + 1, i + 1);
        active_virus.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    grid.resize(N, vector<int>(N));

    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < N; ++c) {
            cin >> grid[r][c];
            if(grid[r][c] == 2) {
                virus_loc.push_back({r, c});
            }
            else if(grid[r][c] == 0) {
                empty_cell_count++;
            }
        }
    }

    if (empty_cell_count == 0) {
        cout << 0 << endl;
        return 0;
    }


    // 바이러스 중 M개를 활성 상태로 변경한다 - 브루트포스
    // 바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다
    combination(0, 0);

    if (min_total_time == 2e9) { // 한 번도 갱신되지 않았다면
        cout << -1 << "\n";
    } else {
        cout << min_total_time << "\n";
    }

    return 0;
}