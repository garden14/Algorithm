#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;

    for(int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while(pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int sum = first + second;
        result += sum;
        pq.push(sum);
    }

    cout << result;

    return 0;
}



// 10 20 40
// 10+20 = 30+ 30+ 40 = 100
// 10+40 = 50 + 50 + 20 = 120
// 최소 몇 번의 비교?