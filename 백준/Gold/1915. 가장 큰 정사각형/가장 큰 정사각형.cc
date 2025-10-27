#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int n, m;
int board[1001][1001];
int dp[1001][1001]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int max_side = 0; 

    for (int i = 1; i <= n; ++i) {
        string row;
        cin >> row;
        for (int j = 1; j <= m; ++j) {
            board[i][j] = row[j - 1] - '0'; 
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] == 1) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                
                max_side = max(max_side, dp[i][j]);
            }
        }
    }

    cout << max_side * max_side << "\n";

    return 0;
}