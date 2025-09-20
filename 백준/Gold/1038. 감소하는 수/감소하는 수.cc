#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> result;

void DFS(long long idx, int cnt){
    if(cnt > 10)
        return;
    result.push_back(idx);
    for(int i = 0; i < 10; ++i){
        if(idx % 10 > i){
            DFS(idx * 10 + i, cnt + 1);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < 10; ++i){
        DFS(i, 1);
    }
    
    sort(result.begin(), result.end());
    
    if(result.size() <= n){
        cout << "-1" << endl;
    } else {
        cout << result[n] << endl;
    }
    
    return 0;
}