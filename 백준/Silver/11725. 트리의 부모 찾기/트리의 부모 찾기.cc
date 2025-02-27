#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> tree[100001];
int parent[100001];

void findParent(int root)
{
    queue<int> q;
    q.push(root);
    parent[root] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : tree[node])
        {
            if (parent[child] == 0)
            {
                parent[child] = node;
                q.push(child);
            }
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    findParent(1);

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
    }

    return 0;
}