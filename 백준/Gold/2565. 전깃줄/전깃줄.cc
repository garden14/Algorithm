#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int N, a, b;
	int result = 0;
	cin >> N;
	
	vector<pair<int, int>> v;
	v.emplace_back(0, 0);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end());
	
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		result = max(result, dp[i]);
	}
	
	cout << N - result << endl;
	return 0;
}