#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

int bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    int result;

    while (!q.empty())
    {
        int person = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (depth >= 2)
            continue;

        for (int f : graph[person])
        {
            if (!visited[f])
            {
                visited[f] = true;
                q.push({f, depth + 1});
                result++;
            }
        }
    }

    return result;
}

int main()
{
    cin >> n;
    cin >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    cout << bfs(1) << endl;

    return 0;
}