#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n, m;
int maxSum = 0;

void dfs(int x, int y, int depth, int sum) {
    if(depth == 4) {
        maxSum = max(maxSum, sum);
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx,ny,depth+1,sum+board[nx][ny]);
        visited[nx][ny] = false;
    }
}

void checkShape(int x, int y) {
    if (x >= 1 && y >= 0 && y + 2 < m) {  // "ㅗ" 
        int sum = board[x][y] + board[x][y + 1] + board[x][y + 2] + board[x - 1][y + 1];
        maxSum = max(maxSum, sum);
    }
    if (x + 1 < n && y >= 0 && y + 2 < m) {  // "ㅜ" 
        int sum = board[x][y] + board[x][y + 1] + board[x][y + 2] + board[x + 1][y + 1];
        maxSum = max(maxSum, sum);
    }
    if (x >= 0 && x + 2 < n && y + 1 < m) {  // "ㅏ" 
        int sum = board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 1][y + 1];
        maxSum = max(maxSum, sum);
    }
    if (x >= 0 && x + 2 < n && y >= 1) {  // "ㅓ" 
        int sum = board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 1][y - 1];
        maxSum = max(maxSum, sum);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    for(int i = 0; i<n; i++) {
        for(int j =0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j =0; j<m; j++) {
            visited[i][j] = true;
            dfs(i,j,1,board[i][j]);
            visited[i][j] = false;
            
            checkShape(i,j);
        }
    }


    cout << maxSum << "\n";
    return 0;
}