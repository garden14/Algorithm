#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i = 0; i < n; ++i) {
        long long card;
        cin >> card;
        pq.push(card);
    }

    for(int i = 0; i < m; ++i) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        long long sum = first + second;
        pq.push(sum);
        pq.push(sum);
    }

    long long result = 0;

    while(!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    cout << result << "\n";

    return 0;
}