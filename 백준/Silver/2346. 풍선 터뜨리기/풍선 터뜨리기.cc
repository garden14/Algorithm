#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    deque<pair<int, int>> dq;

    for (int i = 1; i <= N; ++i) {
        int move;
        cin >> move;
        dq.push_back({i, move}); 
    }

    while (!dq.empty()) {
        pair<int, int> current = dq.front();
        dq.pop_front();
        
        cout << current.first << " "; 
        
        int k = current.second; 

        if (dq.empty()) {
            break;
        }

        if (k > 0) {
            for (int i = 0; i < k - 1; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            k = -k; 
            for (int i = 0; i < k; ++i) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << "\n";
    return 0;
}