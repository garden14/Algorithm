#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX = 100001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> dist(MAX, -1);

    deque<int> dq;

    dq.push_back(N); // 시작 위치
    dist[N] = 0;

    while(!dq.empty()) {
        int current = dq.front();
        dq.pop_front();

        if(current == K) {
            cout << dist[K] << "\n";
            break;
        }

        // 순간이동
        int teleport = current * 2;
        if(teleport < MAX && dist[teleport] == -1) {
            dist[teleport] = dist[current];
            dq.push_front(teleport); // 비용이 0이므로 앞에
        }

        // 뒤로 걷기
        int walk_back = current - 1;
        if(walk_back >= 0 && dist[walk_back] == -1) {
            dist[walk_back] = dist[current] + 1;
            dq.push_back(walk_back); // 비용이 0이므로 앞에
        }

        // 앞으로 걷기
        int walk_front = current + 1;
        if(walk_front < MAX && dist[walk_front] == -1) {
            dist[walk_front] = dist[current] + 1;
            dq.push_back(walk_front); // 비용이 0이므로 앞에
        }
    }


    return 0;
}

// 걷기 1초 후에 X-1 또는 X+1
// 순간이동 0초 후에 2*X