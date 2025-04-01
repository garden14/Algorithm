#include <iostream>
#include <vector>

using namespace std;
const int mod = 1000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string code;
    cin >> code;

    int len = code.length();

    if (code[0] == '0')
        cout << 0;

    else
    {
        vector<int> dp(5001, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= len; i++)
        {
            if (code[i - 1] != '0')
                dp[i] = (dp[i] + dp[i - 1]) % mod;

            int temp = (code[i - 2] - '0') * 10 + (code[i - 1] - '0');
            if (temp >= 10 && temp <= 26)
                dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
        cout << dp[len];
    }
    return 0;
}