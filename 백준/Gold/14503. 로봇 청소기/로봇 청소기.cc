#include <iostream>

using namespace std;

int N, M;
int room[50][50];

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int cnt = 0;

void simulate(int r, int c, int dir) {
    while(true) {
        if(room[r][c] == 0) {
            room[r][c] = 2;
            ++cnt;
        }

        bool find_to_clean = 0;
        for(int i = 0; i < 4; ++i) {
            // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
            // 반시계 방향으로 90도 회전
            // 0 - 북 1 - 동 2 - 남 3 - 서
            // 0 -> 3 / 1 -> 0 / 2 -> 1 / 3 -> 2
            dir = (dir + 3) % 4;

            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if(room[nr][nc] == 0) {
                r = nr;
                c = nc;
                find_to_clean = 1;
                break;
            }
        }

        if(!find_to_clean) {
            // 바라보는 방향 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진
            int back_dir = (dir + 2) % 4;
            int br = r + dr[back_dir];
            int bc = c + dc[back_dir];

            if(room[br][bc] != 1) {
                r = br;
                c = bc;
            }else{
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // 북 동 남 서
    int init_r, init_c, init_dir;
    cin >> init_r >> init_c >> init_dir;

    // 0 : 청소 안 됨 1: 벽
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; ++j) {
            cin >> room[i][j];
        }
    }
    
    simulate(init_r, init_c, init_dir);
    cout << cnt;

    return 0;
}