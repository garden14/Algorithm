#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
int board[20][20];
bool visited[20][20];

int total_time = 0; // 총 걸린 시간
int shark_size = 2; // 상어의 크기
int shark_r, shark_c; // 상어의 위치
int eat_count = 0; // 먹은 물고기 수

// 상하좌우 이동
const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

// 물고기 정보
struct Fish { 
    int r, c, dist;
};

bool compareFish(const Fish& a,const Fish& b) {
    if(a.dist != b.dist) {
        return a.dist < b.dist;
    }

    if(a.r != b.r) {
        return a.r < b.r;
    }

    return a.c < b.c;
}

Fish findFish() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            visited[i][j] = false;
        }
    }

    queue<tuple<int, int, int>> q;
    vector<Fish> candidates;

    q.push({shark_r, shark_c, 0});
    visited[shark_r][shark_c] = true;

    while(!q.empty()) {
        tuple<int, int, int> curr = q.front();
        q.pop();

        int r = get<0>(curr);   
        int c = get<1>(curr);    
        int dist = get<2>(curr); 

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visited[nr][nc]) continue;
            if(board[nr][nc] > shark_size) continue;
            
            visited[nr][nc] = true;

            // 먹을 수 있는 물고기면 후보에 추가
            if(board[nr][nc] > 0 && board[nr][nc] < shark_size) {
                candidates.push_back({nr, nc, dist + 1});
            }

            q.push({nr, nc, dist + 1});
        }
    }
    
    // 먹이 후보 없으면 종료
    if (candidates.empty()) {
        return {-1, -1, -1};
    }

    // 후보들을 정렬하여 최적의 먹잇감을 찾음
    sort(candidates.begin(), candidates.end(), compareFish);
    return candidates[0];

}

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;

    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark_r = i;
                shark_c = j;
                board[i][j] =0; // 있던 자리 0으로
            }
        }
    }

    while(true) {
        Fish target = findFish();

        if (target.dist == -1) {
            break;
        }

        // 물고기 먹고 상태 업데이트
        total_time += target.dist;
        eat_count++;

        // 상어 위치를 먹은 물고기 위치로 이동
        shark_r = target.r;
        shark_c = target.c;
        board[shark_r][shark_c] = 0; // 물고기를 먹어서 빈칸으로 만듦

        // 자신의 크기만큼 물고기를 먹었다면 레벨업
        if (eat_count == shark_size) {
            shark_size++;
            eat_count = 0;
        }
    }

    cout << total_time << '\n';

    return 0;
}