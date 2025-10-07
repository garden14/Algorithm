#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;

void solve() {
    dp[0] = 1;

    for(int coin : coins) {
        for(int i = coin; i <= k; ++i) {
            dp[i] += dp[i - coin];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    coins.resize(n);
    dp.resize(k + 1, 0);

    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    
    solve();
    cout << dp[k] << "\n";

    return 0;
}