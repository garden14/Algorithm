#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> bus[1001];

vector<int> dijkstra(int start, int vertex)
{
    vector<int> distance(vertex, 1000000000);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (pq.size() > 0)
    {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (distance[current] != cost)
        {
            continue;
        }

        for (int i = 0; i < bus[current].size(); i++)
        {
            int next = bus[current][i].first;
            int next_cost = bus[current][i].second;

            if (distance[next] <= next_cost + cost)
            {
                continue;
            }
            distance[next] = next_cost + cost;
            pq.push(make_pair(next_cost + cost, next));
        }
    }

    return distance;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int source, destination, cost;
        cin >> source >> destination >> cost;
        bus[source].push_back(make_pair(destination, cost));
    }

    int start, end;
    cin >> start >> end;

    n++;
    vector<int> result = dijkstra(start, n);

    cout << result[end] << endl;

    return 0;
}