#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N, L, R;
int A[50][50];
int days = 0;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

bool bfs(int r, int c, bool visit[][50]) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> union_countries;

    q.push({r, c});
    visit[r][c] = true;
    union_countries.push_back({r, c});
    int sum = A[r][c];

    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nr = current.first + dr[i];
            int nc = current.second + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

            if(!visit[nr][nc]) {
                int diff = abs(A[current.first][current.second] - A[nr][nc]);
                if(diff >= L && diff <= R) {
                    visit[nr][nc] = true;
                    q.push({nr, nc});
                    union_countries.push_back({nr, nc});
                    sum += A[nr][nc];
                }
            }
        }
    }

    if(union_countries.size() > 1) {
        int new_pop = sum / union_countries.size();
        for(const auto& country : union_countries) {
            A[country.first][country.second] = new_pop;
        }
        return true;
    }

    return false;
}

void simulate() {
    while(true) {
        bool is_moved = false;
        bool visit[50][50] = {false,};
        
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                if(!visit[r][c]) {
                    if(bfs(r, c, visit)) {
                        is_moved = true;
                    }
                }
            }
        }

        if(!is_moved) break;
        days++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    simulate();

    cout << days << "\n";

    return 0;
}