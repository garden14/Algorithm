#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int K;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        cin >> K;

        for(int i = 0; i < K; ++i) {
            long long fileSize;
            cin >> fileSize;
            pq.push(fileSize);
        }

        long long result = 0;

        while(pq.size() > 1) {
            long long file1 = pq.top();
            pq.pop();
            long long file2 = pq.top();
            pq.pop();

            long long sum = file1 + file2;
            result += sum;

            pq.push(sum);
        }

        cout << result << "\n";
    }
    

    return 0;
}

// 두 개의 파일을 합칠 때 필요한 비용은 두 파일 크기의 합
// 최소 비용