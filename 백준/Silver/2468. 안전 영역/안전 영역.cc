#include <iostream>
#include <algorithm>
#include <cstring>

int N;
int height[100][100];
bool visited[100][100];

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int max_height = -2e9;
int max_safe = -2e9;
int cnt;


void dfs(int x, int y, int k){
    for(int i = 0; i < 4; ++i) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
        if(height[next_x][next_y] <= k || visited[next_x][next_y]) continue;

        visited[next_x][next_y] = true;
        dfs(next_x, next_y, k);
    }
}

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> height[i][j];
            if(height[i][j] > max_height)   
                max_height = height[i][j];
        }
    }
    
    for (int k = 0; k <max_height; ++k) {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(visited[i][j] == false && height[i][j] > k){
                    cnt++;
                    dfs(i, j , k);
                } else  
                    visited[i][j] = true;
            }
            max_safe = max(max_safe, cnt);
        }
    }


    cout << max_safe << "\n";
    
    return 0;
}