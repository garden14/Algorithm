#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int visit[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T, G;
    cin >> N >> T >> G;

    for (int i = 0; i < 100000; ++i) {
        visit[i] = -1;
    }

    queue<pair<int, int>> q;

    q.push({N, 0});
    visit[N] = 0;

    while (!q.empty()) {
        int current_num = q.front().first;
        int count = q.front().second;
        q.pop();

        if (current_num == G) {
            cout << count << endl;
            return 0;
        }

        if (count >= T) {
            continue;
        }

        int next_a = current_num + 1;
        if (next_a <= 99999) {
            if (visit[next_a] == -1) {
                visit[next_a] = count + 1;
                q.push({next_a, count + 1});
            }
        }

        int double_num = current_num * 2;
        if (double_num <= 99999 && current_num != 0) {
            int power = 0;
            if(double_num > 0) {
                power = (int)pow(10, (int)log10(double_num));
            }
            int next_b = double_num - power;
            
            if (visit[next_b] == -1) {
                visit[next_b] = count + 1;
                q.push({next_b, count + 1});
            }
        }
    }
    
    cout << "ANG" << endl;

    return 0;
}