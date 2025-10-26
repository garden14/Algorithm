#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        dp[i] = a[i];
        
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    int max_sum = *max_element(dp.begin(), dp.end());

    cout << max_sum << "\n";

    return 0;
}