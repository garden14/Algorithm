#include <iostream>
#include <queue>

using namespace std;

int ladderSnake[101] = {0};  // 사다리와 뱀 정보
bool visited[101] = {0};  // 방문 여부

void bfs(int start, int moves) {
    queue<pair<int, int>> queue;
    queue.push({start, moves});
    visited[start] = true;  // 시작점 방문 체크

    while (!queue.empty()) {
        int current = queue.front().first;
        int cnt = queue.front().second;
        queue.pop();

        for (int i = 1; i <= 6; i++) {  // 주사위 1~6칸 이동
            int nx = current + i;
            if (nx == 100) {  // 도착하면 종료
                cout << cnt + 1;
                return;
            }
            if (nx < 100) {
                while (ladderSnake[nx] != 0) {  // 사다리 또는 뱀 이동
                    nx = ladderSnake[nx];
                }
                if (!visited[nx]) {  // 방문하지 않았다면 큐에 추가
                    visited[nx] = true;
                    queue.push({nx, cnt + 1});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {  // 사다리 입력
        cin >> x >> y;
        ladderSnake[x] = y;
    }

    for (int i = 0; i < m; i++) {  // 뱀 입력
        cin >> x >> y;
        ladderSnake[x] = y;
    }

    bfs(1, 0);  // 시작점 1에서 BFS 실행

    return 0;
}
