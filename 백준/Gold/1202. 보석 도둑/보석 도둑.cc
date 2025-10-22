#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels;
    vector<int> bags;

    for(int i = 0; i < N; ++i) {
        int m, v;
        cin >> m >> v;
        jewels.push_back({m, v});
    }

    for(int i = 0; i < K; ++i) {
        int c;
        cin >> c;
        bags.push_back(c);
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    priority_queue<int> jewels_pq;
    long long result = 0;
    int idx = 0;
    
    for(int i = 0; i < K; ++i) {
        int current_bag = bags[i];

        while(idx < N && jewels[idx].first <= current_bag) {
            jewels_pq.push(jewels[idx].second);
            idx++;
        }

        if(!jewels_pq.empty()) {
            result += jewels_pq.top();
            jewels_pq.pop();
        }
    }

    cout << result << "\n";
    
    return 0;
}

// 보석 N개 - 무게 M 가격 V
// 가방 K개
// 각 가방에 담을 수 있는 최대 무게는 C
// 가방에는 최대 한 개의 보석
// 보석의 최대 가격
// 가방에 넣을 수 있는 보석 중 가장 비싼 보석이어야 함