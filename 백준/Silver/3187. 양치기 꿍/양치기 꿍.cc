#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

int r, c;
int v, k;
char map[250][250];
bool visit[250][250] = { false, };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
	
	int vnum = 0;
	int knum = 0;

	queue<pair<int, int>> q;

	visit[y][x] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;

		if (map[cy][cx] == 'k')
			knum++;
		else if (map[cy][cx] == 'v')
			vnum++;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = cx + dx[i];
			int ty = cy + dy[i];

			if (tx < 0 || tx >= c || ty < 0 || ty >= r)
				continue;
			if (visit[ty][tx] || map[ty][tx] == '#')
				continue;

			visit[ty][tx] = true;
			q.push({ tx, ty });
		}
	}

	if (vnum >= knum) {
		k -= knum;
	}
	else {
		v -= vnum;
	}

}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'v')
				v++;
			else if (map[i][j] == 'k')
				k++;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visit[i][j] && map[i][j] != '#') {
				bfs(j, i);
			}
		}
	}

	cout << k << " " << v;

	return 0;
}
