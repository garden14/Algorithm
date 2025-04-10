#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, e;
int v1, v2;
vector<pair<int, int>> nodes[801];

vector<int> dijkstra(int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (cost > dist[current]) continue;

        for (auto next : nodes[current]) {
            int next_node = next.first;
            int next_cost = next.second;

            if (dist[next_node] > cost + next_cost) {
                dist[next_node] = cost + next_cost;
                pq.push({-dist[next_node], next_node});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({b, c});
        nodes[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    vector<int> from1 = dijkstra(1);
    vector<int> fromV1 = dijkstra(v1);
    vector<int> fromV2 = dijkstra(v2);

    int path1 = from1[v1] + fromV1[v2] + fromV2[n];
    int path2 = from1[v2] + fromV2[v1] + fromV1[n];

    int result = min(path1, path2);
    if (result >= INF || from1[v1] >= INF || fromV1[v2] >= INF || fromV2[n] >= INF) {
        cout << -1 << '\n';
    } else {
        cout << result << '\n';
    }

    return 0;
}
