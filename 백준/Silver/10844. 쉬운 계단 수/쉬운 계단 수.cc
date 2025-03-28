#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int dp[101][11] = {0,};

    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j + 1] % 1000000000;
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            }
            else{
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }                
        }
    }

    long long answer = 0;
    for (int i = 0; i < 10; i++)
    {
        answer = (answer + dp[n][i]) % 1000000000;
    }

    cout << answer;
    return 0;
}