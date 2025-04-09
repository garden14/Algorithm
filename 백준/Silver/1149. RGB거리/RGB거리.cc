#include <iostream>
#include <string>

int dp[1001][3] = {
    0,
};

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }

    int result = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << result;
    return 0;
}