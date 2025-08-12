#include <iostream>
using namespace std;

int N, M, W, B;
char map[100][100];
int visit[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int tmp;

void dfs(int x, int y) {
	if (visit[x][y]) return;

	tmp++;
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cx < M && cy >= 0 && cy < N && !visit[cx][cy] && map[cx][cy] == map[x][y]) {
			dfs(cx, cy);
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				tmp = 0;
				dfs(i, j);
				if (map[i][j] == 'W') W += tmp * tmp;
				else B += tmp * tmp;
			}
		}
	}

	cout << W << " " << B << endl;
}
