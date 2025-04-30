#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K;
vector<pair<int, int>> v;
bool trash[101][101];
bool check[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int result = 0;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    int count = 1;

    q.push({ a,b });
    check[a][b] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny > N || nx > M) continue;
            if (check[ny][nx]) continue;
            if (!trash[ny][nx]) continue;

            q.push({ ny,nx });
            check[ny][nx] = true;
            count++;
        }
    }

    result = max(result, count);
}

void solution() {
    for (int i = 0; i < K; i++) {
        memset(check, false, sizeof(check));
        bfs(v[i].first, v[i].second);
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    cin >> N >> M >> K;

    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
        trash[a][b] = true;
    }

    solution();

    return 0;
}