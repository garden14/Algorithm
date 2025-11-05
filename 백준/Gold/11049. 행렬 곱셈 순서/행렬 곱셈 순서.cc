#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int NUM_MAX = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int ,int>> matrix(N);
    int dp[500][500];


    for(int i = 0; i < N; ++i) {
        cin >> matrix[i].first >> matrix[i].second;
    }

    for(int len = 2; len <= N; ++len){
        for(int i = 0; i <= N - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = NUM_MAX;

            for(int k = i; k < j; ++k) {
                int cost = matrix[i].first * matrix[k].second * matrix[j].second;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost);
            }
        }
    }

    cout << dp[0][N-1] << "\n";

    return 0;
}