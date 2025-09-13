#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K;
    
	vector<string> arr(N);
	vector<vector<int>> fromW(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> fromB(N + 1, vector<int>(M + 1, 0));

	for (int i = 0; i < N; ++i) cin >> arr[i];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			fromW[i + 1][j + 1] = !(((i + j) % 2 == 0) == (arr[i][j] == 'W'));
			fromB[i + 1][j + 1] = !(((i + j) % 2 == 0) == (arr[i][j] == 'B'));
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			fromW[i][j] += fromW[i - 1][j] + fromW[i][j - 1] - fromW[i - 1][j - 1];
			fromB[i][j] += fromB[i - 1][j] + fromB[i][j - 1] - fromB[i - 1][j - 1];
		}
	}

	int mini = 2e9;
	for (int i = 0; i + K <= N; ++i) {
		for (int j = 0; j + K <= M; ++j) {
			int w = fromW[i + K][j + K] - fromW[i][j + K] - fromW[i + K][j] + fromW[i][j];
			int b = fromB[i + K][j + K] - fromB[i][j + K] - fromB[i + K][j] + fromB[i][j];
			mini = min({ mini, w, b });
		}
	}
	cout << mini;

	return 0;
}