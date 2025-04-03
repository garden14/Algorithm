#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX];
int result[MAX];
bool visited[MAX];

void dfs(int a, int b)
{
    if (b == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                result[b] = arr[i - 1];
                dfs(i + 1, b + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    dfs(1, 0);

    return 0;
}