#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> T(N+1); // 상담 기간
    vector<int> P(N+1); // 상담 비용

    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }

    vector<int> dp(N+2, 0);

    for(int i = N; i >= 1; --i) {
        int next_day = i + T[i];

        if(next_day > N + 1) { // 상담기간이 퇴사일을 초과
            dp[i] = dp[i + 1]; 
        } else {
            dp[i] = max(dp[i+1], P[i] + dp[next_day]);
        }

    }
    
    cout << dp[1] << "\n";

    return 0;
}