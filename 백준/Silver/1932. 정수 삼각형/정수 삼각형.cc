#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[501][501];
int triangle[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;


    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }
    
    dp[0][0] = triangle[0][0];
    // dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j == 0){ // 맨 왼쪽
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if(j == i) { // 맨 오른쪽
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else { // 중간
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }

    int max_sum = 0;
    for (int j = 0; j < n; ++j) {
        if (dp[n-1][j] > max_sum) {
            max_sum = dp[n-1][j];
        }
    }

    cout << max_sum << "\n";

    return 0;
}