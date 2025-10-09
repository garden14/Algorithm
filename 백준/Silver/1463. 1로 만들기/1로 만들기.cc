#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1000001];

void solve() {
    // N - 1을 1로 만들기 위한 최소 횟수 + 1
    // 2, 3으로 나눠질 경우 나눠지고 남은 몫에 대한 경우의 연산 +1

    for(int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1;

        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }

        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }

    cout << dp[N];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    solve();
    
    return 0;
}