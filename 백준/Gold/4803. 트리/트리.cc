#include <iostream>
#include <vector>
 
using namespace std;
 
int n, m;
bool flag;
 
void dfs(int cur, int prev, vector<vector<int>>& tree, vector<int>& visited)
{
    visited[cur] = 1;
 
    for (auto nxt : tree[cur])
    {
        if (nxt == prev) continue;

        if (visited[nxt])
        {   
            flag = false;
            continue;
        }

        dfs(nxt, cur, tree, visited);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int idx = 1;
    while (idx)
    {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        vector<vector<int>> tree(n + 1);
        vector<int> visited(n + 1, 0);
 
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
 
        int cnt = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (visited[i]) continue;
            cnt++;
            flag = 1;
            dfs(i, -1, tree, visited);
            if (!flag) cnt--;
        }
 
        cout << "Case " << idx << ": ";
        if (cnt == 0)
        {
            cout << "No trees.\n";
        }
        else if (cnt == 1)
        {
            cout << "There is one tree.\n";
        }
        else
        {
            cout << "A forest of " << cnt << " trees.\n";
        }
        idx++;
    }
 
    return 0;
}