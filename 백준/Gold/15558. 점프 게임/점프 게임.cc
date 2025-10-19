#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct State {
    int line;
    int col;
    int time;
};

int n, k;
vector<string> board(2);
bool visited[2][100001];

int bfs() {
    queue<State> q;

    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int current_line = current.line;
        int current_col = current.col;
        int current_time = current.time;

        int next_moves[3][2] = {
            {current_line, current_col + 1},
            {current_line, current_col - 1},
            {1 - current_line, current_col + k}
        };

        for (int i = 0; i < 3; ++i) {
            int next_line = next_moves[i][0];
            int next_col = next_moves[i][1];

            if (next_col >= n) {
                return 1;
            }

            if (next_col < 0) {
                continue;
            }
            
            if (next_col <= current_time) {
                continue;
            }

            if (board[next_line][next_col] == '0' || visited[next_line][next_col]) {
                continue;
            }

            visited[next_line][next_col] = true;
            q.push({next_line, next_col, current_time + 1});
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> board[0] >> board[1];

    cout << bfs() << endl;

    return 0;
}