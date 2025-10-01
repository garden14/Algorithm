#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
const int INF = 2e9;
int work[20][20];
int dp[20][1<<20]; // dp[person][mask]

int solve(int person, int mask) {
    if(person == N) {
        return 0;
    }

    if(dp[person][mask] != -1) {
        return dp[person][mask];
    }

    int& ret = dp[person][mask];
    ret = INF;

    // person에게 배정할 일을 선택
    for (int i = 0; i < N; ++i) {
        // i번째 일이 아직 배정되지 않았다면 (mask의 i번째 비트가 0이라면)
        if (!(mask & (1 << i))) {
            // person에게 i번 일을 배정하고, 다음 사람으로 넘어감
            // mask에는 i번 일을 배정했다는 의미로 i번째 비트를 켬
            ret = min(ret, work[person][i] + solve(person + 1, mask | (1 << i)));
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;


    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
        cin >> work[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0);

    return 0;
}