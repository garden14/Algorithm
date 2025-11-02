#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> 

using namespace std;

#define MAX 100001

int dist[MAX]; 
int parent[MAX]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    fill(dist, dist + MAX, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    parent[n] = n; 
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == k) {
            break;
        }

        int next_positions[3] = {now - 1, now + 1, now * 2};

        for (int next : next_positions) {
            if (next >= 0 && next < MAX && dist[next] == -1) {
                q.push(next);
                dist[next] = dist[now] + 1; 
                parent[next] = now;        
            }
        }
    }

    cout << dist[k] << '\n';

    vector<int> path;
    int temp = k;

    while (temp != n) {
        path.push_back(temp);
        temp = parent[temp];
    }
    path.push_back(n); 

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << '\n';

    return 0;
}