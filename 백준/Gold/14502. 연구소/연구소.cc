#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int grid[8][8]; // 원본 배열
int temp[8][8]; 

vector<pair<int, int>> empty_cells;
vector<pair<int, int>> virus_loc;

int max_safe_area = 0;

// 상하좌우
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

void simulate() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            temp[i][j] = grid[i][j];
        }
    }

    queue<pair<int,int>> q;
    for(const auto& virus : virus_loc) {
        q.push(virus);
    }

    while(!q.empty()) {
        pair<int, int> current = q.front();
        int r = current.first;
        int c = current.second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M || temp[nr][nc] != 0) continue;
            temp[nr][nc] = 2;
            q.push({nr,nc});
        }
    }

    int current_safe_area = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(temp[i][j] == 0) {
                current_safe_area++;
            }
        }
    }

    max_safe_area = max(max_safe_area, current_safe_area);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 0) {
                empty_cells.push_back({i, j});
            }else if(grid[i][j] == 2) {
                virus_loc.push_back({i, j});
            }
        }
    }

    // 벽 세울 좌표 브루트 포스
    for(int i = 0; i < empty_cells.size(); ++i) {
        for(int j = i + 1; j < empty_cells.size(); ++j) {
            for(int k = j + 1; k < empty_cells.size(); ++k) {
                grid[empty_cells[i].first][empty_cells[i].second] = 1;
                grid[empty_cells[j].first][empty_cells[j].second] = 1;
                grid[empty_cells[k].first][empty_cells[k].second] = 1;
                
                // 벽 세워진 상태에서 bfs
                simulate();

                // 다시 허물기
                grid[empty_cells[i].first][empty_cells[i].second] = 0;
                grid[empty_cells[j].first][empty_cells[j].second] = 0;
                grid[empty_cells[k].first][empty_cells[k].second] = 0;
            }
        }
    }

    cout << max_safe_area;

    return 0;
}