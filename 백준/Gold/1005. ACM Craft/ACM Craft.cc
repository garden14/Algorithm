#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    // 건설 시간
    vector<int> time(N + 1);
    for(int i = 1; i <= N; ++i) {
        cin >> time[i];
    }

    // 건설 규칙
    vector<vector<int>> adj(N + 1); // 특정 건물을 지은 후 지을 수 있는 건물 목록
    vector<int> indegree(N + 1, 0); // 특정 건물을 짓기 위해 먼저 지어야 하는 건물 수

    for(int i = 0; i < K; ++i) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        indegree[Y]++;
    }

    int target;
    cin >> target;

    queue<int> q;
    vector<int> result(N+1, 0);

    // 진입 차수가 0인 건물은 바로 시작할 수 있음
    for(int i = 1; i <= N; ++i) {
        if(indegree[i] == 0) {
            q.push(i);
            result[i] = time[i];
        }
    }

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int next : adj[current]) {
            result[next] = max(result[next], result[current] + time[next]);

            indegree[next]--;

            if(indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    cout << result[target] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}

// 매 게임 시작 시 건물 짓는 순서가 주어짐
// 모든 건물은 각각 건설을 시작하여 완성이 될 때까지 딜레이 존재
// 특정 건물을 가장 빨리 지을 때까지 걸리는 최소 시간