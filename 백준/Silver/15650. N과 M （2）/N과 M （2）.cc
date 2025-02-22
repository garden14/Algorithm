#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX];

void dfs(int a, int b)
{
    if (b == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = a; i <= n; i++)
        {
            arr[b] = i;
            dfs(i + 1, b + 1);
        }
    }
}
int main()
{
    cin >> n >> m;
    dfs(1, 0);

    return 0;
}