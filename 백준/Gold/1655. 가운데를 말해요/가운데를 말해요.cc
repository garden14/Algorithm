#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    cin >> N;

    int input_num;
    
    while(N--) {
        cin >> input_num;
        
        if(max_pq.size() == min_pq.size()) {
            max_pq.push(input_num);
        } else {
            min_pq.push(input_num);
        }

        if(!min_pq.empty() && (max_pq.top() > min_pq.top())) {
            int max_top = max_pq.top();
            int min_top = min_pq.top();

            max_pq.pop();
            min_pq.pop();

            max_pq.push(min_top);
            min_pq.push(max_top);
        }

        cout << max_pq.top() << "\n";
    }
    

    return 0;
}

// 중간 값 찾기
// 짝수개라면 중간에 있는 수 중 작은 수
// 말해야 하는 수 출력
// 최대 힙 : 중간 값보다 작거나 같은 수 저장
// 최소 힙 : 중간 값보다 큰 수 저장
// 최대 힙의 top이 중간 값이 됨
// 최대 힙의 크기는 최소 힙보다 같거나 1 커야 함
// 최대 힙의 top은 항상 최소 힙의 top보다 작거나 같아야 한다.