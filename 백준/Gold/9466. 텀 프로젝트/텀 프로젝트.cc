#include <iostream>
#include <cstring>

using namespace std;

int n;
int choose[100001];
int state[100001]; // 0 : 방문 ㄴ 1 : 방문 중 2 : 방문 완
int cnt;

void dfs(int current) {
    state[current] = 1;

    int next = choose[current];

    if(state[next] == 1) {
        int temp = next;
        while(temp != current) {
            cnt++;
            temp = choose[temp];
        }
        cnt++;
    }
    else if(state[next] == 0) {
        dfs(next);
    }
    state[current] = 2;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> choose[i];
    }

    memset(state, 0, sizeof(state));
    cnt = 0;
    
    for(int i = 1; i <= n; ++i) {
        if(state[i] == 0) { 
            dfs(i);
        }
    }

    cout << n - cnt << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // 어느 프로젝트 팀에도 속하지 않은 학생들의 수

    while(T--) {
        solve();
    }

    return 0;
}