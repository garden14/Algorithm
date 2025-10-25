#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int dp[31];
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for(int i = 3; i <= N; ++i) {
        if(i % 2 != 0) dp[i] = 0;
        else {
            for(int j = 2; j <= N; ++j) {
                if(j == 2) dp[i] = dp[i - j] * dp[2];
                else if((i - j) >= 0) dp[i] += dp[i - j] * 2;
            }
        }
    }

    cout << dp[N] << "\n";

    return 0;
}

// dp[1] = 0 / dp[2] = 3 / dp[3] = 0
// 홀수일 땐 0
