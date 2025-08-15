#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[10001];
bool visited[10001];
int hackedCount[10001] = {0,};

int bfs(int startNode) {
    fill(visited + 1, visited + 10001, false);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;
    int count = 0;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        count++;

        for (int nextNode : adj[currentNode]) {
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[B].push_back(A);
    }

    int maxCount = 0;
    for (int i = 1; i <= N; ++i) {
        hackedCount[i] = bfs(i);
        if (hackedCount[i] > maxCount) {
            maxCount = hackedCount[i];
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (hackedCount[i] == maxCount) {
            cout << i << " ";
        }
    }

    return 0;
}