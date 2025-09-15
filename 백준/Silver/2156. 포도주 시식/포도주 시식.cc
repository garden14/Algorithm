#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    cin >> n;
    
    int a[10001] = {0};
    int dp[10001] = {0};
    
    for(int i = 1; i <= n; ++i) cin >> a[i];
    
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    
    for(int i = 3; i <= n; ++i){
        dp[i] = max({dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i], dp[i - 1]});
    }
    cout << dp[n];
}