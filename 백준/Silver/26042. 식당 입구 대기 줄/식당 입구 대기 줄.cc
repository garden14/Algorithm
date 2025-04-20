#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> que;

int mx, id;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	cin >> N;

	while (N--) {
		int x; cin >> x;
		if (x == 1) {
			int y; cin >> y;
			que.push(y);
			if (que.size() > mx || (que.size() == mx && y < id)) mx = que.size(), id = y;
		}
		else que.pop();
	}

	cout << mx << ' ' << id;
}