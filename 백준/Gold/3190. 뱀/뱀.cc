#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int board[101][101];
int N, K, L;

int dr[] = {0,1,0,-1}; // 우하좌상
int dc[] = {1,0,-1,0};

vector<pair<int, char>> dir_changes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> K;

    for(int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }

    cin >> L;

    for(int i = 0; i < L; ++i) {
        int x;
        char d;
        cin >> x >> d;
        dir_changes.push_back({x, d});
    }
    
    deque<pair<int, int>> snake;

    // init
    int time = 0;
    int dir = 0; 
    int change_idx = 0; // 방향 전환 정보 vector의 인덱스

    snake.push_front({1, 1}); // 뱀은 (1, 1)에서 시작
    board[1][1] = 2; // 뱀은 2로 표시

    while (true) {
        time++;

        // 뱀 머리의 현재 위치
        int r = snake.front().first;
        int c = snake.front().second;

        // 다음 머리가 위치할 곳
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        // 종료 조건 
        // 벽에 부딪히는 경우
        if (nr < 1 || nr > N || nc < 1 || nc > N) {
            break;
        }
        // 자기 몸에 부딪히는 경우
        if (board[nr][nc] == 2) {
            break;
        }

        // 뱀 이동 
        // 사과가 없는 경우
        if (board[nr][nc] != 1) {
            // 꼬리가 있던 칸을 빈 칸(0)으로 만듦
            int tail_r = snake.back().first;
            int tail_c = snake.back().second;
            board[tail_r][tail_c] = 0;
            // 덱에서 꼬리 제거
            snake.pop_back();
        } else { // 사과가 있는 경우
            // 사과를 먹었으므로 board에서 사과를 없앰
            board[nr][nc] = 0;
            // 꼬리는 그대로 둠 (몸 길이 증가)
        }

        // 머리를 다음 칸으로 이동
        snake.push_front({nr, nc});
        board[nr][nc] = 2; // 새로운 머리 위치를 2로 표시

        // 5. 방향 전환 확인
        if (change_idx < L && time == dir_changes[change_idx].first) {
            char change_dir = dir_changes[change_idx].second;
            if (change_dir == 'D') { // 오른쪽으로 90도 회전
                dir = (dir + 1) % 4;
            } else { // 왼쪽으로 90도 회전
                dir = (dir + 3) % 4;
            }
            change_idx++;
        }
    }

    cout << time << "\n";

    return 0;
}