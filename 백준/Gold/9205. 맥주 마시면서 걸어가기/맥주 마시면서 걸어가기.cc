#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int get_distance(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> locations(n+2);

        for(int i = 0; i < n + 2; ++i) {
            cin >> locations[i].first >> locations[i].second;
        }

        queue<int> q;
        vector<bool> visit(n+2, false);

        q.push(0);
        visit[0] = true;

        bool found = false;

        while(!q.empty()) {
            int current = q.front();
            q.pop();

            pair<int, int> current_pos = locations[current];

            if(current == n + 1){
                found = true;
                break;
            }

            for(int next = 0; next < n + 2; ++ next) {
                if(!visit[next]) {
                    pair<int, int> next_pos = locations[next];

                    if (get_distance(current_pos, next_pos) <= 1000) {
                    visit[next] = true; 
                    q.push(next);      
                    }
                }
            }
        }

        if(found) {
            cout << "happy\n";
        }else {
            cout << "sad\n";
        }
    }



    return 0;
}