#include <iostream>
#include <algorithm>

using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    vector<int> crane;
    vector<int> box;
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        crane.push_back(x);
    }
    
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        box.push_back(x);
    }
    
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());
    
    int cnt = 0;
    if (crane.back() < box.back()) {
        cout << -1;
        return 0;
    }
    
    while (!box.empty()) {
        cnt++;
        for (int i = crane.size() - 1; i >= 0; --i) {
            for (int j = box.size() - 1; j >= 0; --j) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    
    cout << cnt;
    return 0;
}