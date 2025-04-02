#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 9876543;
vector<pair<int, int>> nodes[300001];
int dist[20001];

int v, e, k;

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0,k});
    dist[k] = 0;
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int current = pq.top().second;

        pq.pop();

        if(cost > dist[current]) continue;

        for(int i= 0; i<nodes[current].size(); i++) {
            int next_node = nodes[current][i].first;
            int next_cost = cost + nodes[current][i].second;

            if(next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.push(make_pair(-dist[next_node], next_node));
            }
        }
    }

    for(int i=1; i<=v; i++) {
        if(dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    cin >> k;

    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        nodes[x].push_back(make_pair(y, z));
    }

    for (int i = 1; i <= v; i++)
    {
        dist[i] = INF;
    }

    dijkstra();

    return 0;
}