#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool visited[9];

void dfs(int k) {
    if(k == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            arr[k] = i;
            visited[i] = true;

            dfs(k+1);

            visited[i] = false;
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    dfs(0); 
    
    return 0;
}