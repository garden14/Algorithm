#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int l;
int map[300][300];
queue<pair<int, int>> q;

int dx[] = {1, 2, 2, 1, -1, -2, -1, -2};
int dy[] = {2, 1, -1, -2, -2, -1, 2, 1};

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < l && 0 <= ny && ny < l)
            {
                if(map[nx][ny] == -1) {
                    map[nx][ny] = map[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        memset(map, -1, sizeof(map));
        cin >> l;
        int current_x, current_y;
        int target_x, target_y;

        cin >> current_x >> current_y;
        cin >> target_x >> target_y;

        q.push(make_pair(current_x, current_y));
        map[current_x][current_y] = 0;

        bfs();

        cout << map[target_x][target_y] << '\n';
    }

    return 0;
}