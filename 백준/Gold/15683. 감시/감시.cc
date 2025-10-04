#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int initial_office[8][8];
vector<pair<int, int>> cctv_pos;
int res = 2e9;

int dr[] = {-1,0,1,0}; // 상 우 하 좌
int dc[] = {0,1,0,-1};

void watch(int r, int c, int dir, int temp[8][8]) {
    dir %= 4;
    while(true) {
        r += dr[dir];
        c += dc[dir];

        if(r < 0 || r >= N || c < 0 || c >= M || temp[r][c] == 6) return;

        if(temp[r][c] == 0) {
            temp[r][c] = 7;
        }
    }
}

void simulate(int cctv_idx, int current_office[8][8]) {
    
    if(cctv_idx == cctv_pos.size()){
        int blind = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(current_office[i][j] == 0) { 
                    blind++;
                }
            }
        }
        res = min(res, blind);
        return;
    }

    int r = cctv_pos[cctv_idx].first;
    int c = cctv_pos[cctv_idx].second;
    int cctv_type = initial_office[r][c];
    int temp[8][8];

    if (cctv_type == 1) {
        for (int dir = 0; dir < 4; ++dir) {
            copy(&current_office[0][0], &current_office[0][0] + 64, &temp[0][0]);
            watch(r, c, dir, temp);
            simulate(cctv_idx + 1, temp);
        }
    } else if (cctv_type == 2) {
        // 0: 가로(좌우), 1: 세로(상하)
        for (int dir = 0; dir < 2; ++dir) {
            copy(&current_office[0][0], &current_office[0][0] + 64, &temp[0][0]);
            watch(r, c, dir, temp);
            watch(r, c, dir + 2, temp);
            simulate(cctv_idx + 1, temp);
        }
    } else if (cctv_type == 3) {
        for (int dir = 0; dir < 4; ++dir) {
            copy(&current_office[0][0], &current_office[0][0] + 64, &temp[0][0]);
            watch(r, c, dir, temp);
            watch(r, c, dir + 1, temp);
            simulate(cctv_idx + 1, temp);
        }
    } else if (cctv_type == 4) {
        for (int dir = 0; dir < 4; ++dir) {
            copy(&current_office[0][0], &current_office[0][0] + 64, &temp[0][0]);
            watch(r, c, dir, temp);
            watch(r, c, dir + 1, temp);
            watch(r, c, dir + 2, temp);
            simulate(cctv_idx + 1, temp);
        }
    } else if (cctv_type == 5) {
        copy(&current_office[0][0], &current_office[0][0] + 64, &temp[0][0]);
        watch(r, c, 0, temp);
        watch(r, c, 1, temp);
        watch(r, c, 2, temp);
        watch(r, c, 3, temp);
        simulate(cctv_idx + 1, temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> initial_office[i][j];

            if(initial_office[i][j] >= 1 && initial_office[i][j] <= 5) {
                cctv_pos.push_back({i, j});
            }
        }
    }

    simulate(0, initial_office);
    cout << res << "\n";

    return 0;
}