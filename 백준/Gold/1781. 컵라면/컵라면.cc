#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> solve;
    priority_queue<int, vector<int>, greater<int>> cupramen; 
    
    for(int i = 0; i < N; ++i) {
        int deadline, ramen;
        cin >> deadline >> ramen;
        solve.push_back({deadline, ramen});
    }

    sort(solve.begin(),solve.end());

    for(int i = 0; i < N; ++i) {
        int deadline = solve[i].first;
        int ramen = solve[i].second;

        cupramen.push(ramen);

        if(cupramen.size() > deadline) {
            cupramen.pop();
        }
    }

    long long result = 0;
    while(!cupramen.empty()) {
        result += cupramen.top();
        cupramen.pop();
    }

    cout << result << "\n";

    return 0;
}

// 받은 수 있는 최대 컵라면 수 
// 경과시간이 데드라인보다 작거나 같아야 한다
// 그 중에서 받을 수 있는 컵라면의 개수가 높으면 된다