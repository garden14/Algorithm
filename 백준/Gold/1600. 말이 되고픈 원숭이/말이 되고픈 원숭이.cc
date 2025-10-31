#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 201;

int K;
int W, H;
int board[MAX][MAX];
bool visit[MAX][MAX][31];

int monkey_dr[] = {1, -1, 0, 0};
int monkey_dc[] = {0, 0, 1, -1};

int horse_dr[] = {1, 2, 2, 1, -1, -2, -2, -1};
int horse_dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};


struct State {
    int y;     
    int x;     
    int k;     
    int moves; 
};

bool isValid(int y, int x) {
    return (y >= 0 && y < H && x >= 0 && x < W);
}

int solve() {
    queue<State> q;

    q.push({0, 0, 0, 0});
    visit[0][0][0] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.y == H - 1 && current.x == W - 1) {
            return current.moves; 
        }

        for (int i = 0; i < 4; ++i) {
            int ny = current.y + monkey_dc[i];
            int nx = current.x + monkey_dr[i];
            int nk = current.k;

            if (isValid(ny, nx) && board[ny][nx] == 0 && !visit[ny][nx][nk]) {
                visit[ny][nx][nk] = true;
                q.push({ny, nx, nk, current.moves + 1});
            }
        }

        if (current.k < K) {
            for (int i = 0; i < 8; ++i) {
                int ny = current.y + horse_dc[i];
                int nx = current.x + horse_dr[i];
                int nk = current.k + 1;
                if (isValid(ny, nx) && board[ny][nx] == 0 && !visit[ny][nx][nk]) {
                    visit[ny][nx][nk] = true;
                    q.push({ny, nx, nk, current.moves + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    cin >> W >> H;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];
        }
    }

    cout << solve() << "\n";

    return 0;
}