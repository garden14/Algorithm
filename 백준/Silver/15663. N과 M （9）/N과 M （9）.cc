#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
int result[MAX];
bool visited[MAX];

void dfs(int b)
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
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && temp!=arr[i])
            {
                result[b] = arr[i];
                temp = arr[i];
                visited[i] = true;
                dfs(b+1);
                visited[i]= false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr,arr+n);

    dfs(0);
}