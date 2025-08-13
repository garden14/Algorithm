#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int dp[100001] = {1,3};
    cin >> N;
    
    for(int i=2; i<=N; i++) {
        dp[i] = (dp[i-1]*2 + dp[i-2])%9901;
    }

    cout << dp[N];

    return 0;
}