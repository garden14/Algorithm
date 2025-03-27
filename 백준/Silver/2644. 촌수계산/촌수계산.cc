#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int n, m, p1, p2;
int arr[MAX][MAX];
int visited[MAX];
queue<int> q;

void bfs(int p)
{
    q.push(p);
    visited[p] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if(arr[current][i] != 0 && !visited[i]) {
                visited[i] = visited[current] + 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> p1 >> p2;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    bfs(p1);

    
    cout << (visited[p2] ? visited[p2] -1 : -1);
    

    return 0;
}