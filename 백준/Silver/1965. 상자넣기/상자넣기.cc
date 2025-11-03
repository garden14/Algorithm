#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }

    vector<int> dp(n);

    int max_lis = 0; 

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;

        for (int j = 0; j < i; ++j) {
            if (boxes[j] < boxes[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        max_lis = max(max_lis, dp[i]);
    }

    std::cout << max_lis << "\n";

    return 0;
}