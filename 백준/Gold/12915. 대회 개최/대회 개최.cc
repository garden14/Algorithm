#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int E, EM, M, MH, H;

bool is_possible(int K) {
    int needed_EM = max(0, K - E);
    int needed_MH = max(0, K - H);

    if (needed_EM > EM || needed_MH > MH) {
        return false;
    }

    int remain_EM = EM - needed_EM;
    int remain_MH = MH - needed_MH;

    if (remain_EM + M + remain_MH >= K) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> E >> EM >> M >> MH >> H;

    int left = 0;
    int right = E + EM + M + MH + H; 
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (is_possible(mid)) {
            ans = mid;    
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }

    cout << ans << "\n";

    return 0;
}