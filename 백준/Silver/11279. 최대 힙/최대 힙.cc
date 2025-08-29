#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, x;
    cin >> N;

    vector<int> result;
    priority_queue<int> q;

    for(int i = 0; i < N; ++i) {
        cin >> x;
        if(x != 0) {
            q.push(x);}
        else {
            if(q.empty()) {
                result.push_back(0);
            }
            else {
                result.push_back(q.top());
                q.pop();
            }
        }
    }

    for(int num : result) {
        cout << num << "\n";
    }
   
    return 0;
}