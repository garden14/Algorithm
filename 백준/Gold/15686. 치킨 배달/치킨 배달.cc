#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, answer = 2e9;
int city[51][51];

vector<pair<int, int>> chiken;
vector<pair<int, int>> home;
vector<pair<int, int>> Points;


int calc()
{
    int sum = 0;

    for (int i = 0; i < home.size(); ++i)
    {
        int min_d = 2e9;

        for (int j = 0; j < Points.size(); ++j)
        {
            int x = abs(Points[j].first - home[i].first);
            int y = abs(Points[j].second - home[i].second);

            min_d = min(min_d, x + y);
        }

        sum += min_d;
    }

    return sum;
}

void dfs(int idx)
{
    if (Points.size() == m)
    {
        answer = min(answer, calc());
        return;
    }

    for (int i = idx; i < chiken.size(); ++i)
    {
	    Points.push_back(chiken[i]);
	    dfs(i + 1);
	    Points.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> city[i][j];

            if(city[i][j] == 2)
                chiken.push_back({i, j});
            else if(city[i][j] == 1)
                home.push_back({i, j});
        }
    }

    dfs(0);
    
    cout << answer;
   

    return 0;
}