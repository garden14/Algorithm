#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n + 1);
    vector<int> dp(k+1, 10001);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[k] == 10001)
    {
        cout << -1 << "\n";
    }
    else{
        cout << dp[k] << "\n";
    }

    return 0;
}