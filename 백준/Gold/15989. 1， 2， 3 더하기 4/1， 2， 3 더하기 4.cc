#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10001;
vector<vector<int>> dp;

void solve() {
    dp.resize(MAX, vector<int>(4, 0));
    dp[0][1] = dp[1][1] = dp[2][1] = dp[2][2] = 1;

    for(int i = 3; i < MAX; ++i) {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;

    solve();

    // 정수 n을 1,2,3의 합으로 나타내는 방법의 수

    cin >> T;

    for(int i = 0; i < T; ++i) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
    

    return 0;
}