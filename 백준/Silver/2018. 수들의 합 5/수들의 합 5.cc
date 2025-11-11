#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 연속된 자연수의 합

    int start = 1;
    int end = 1;
    int current_sum = 1;
    int count = 0;

    while(start <= N) {
        if(current_sum == N) { // N을 찾은 경우
            count++;
            end++;
            current_sum += end;
        }
        else if(current_sum > N) { // N보다 합이 큰 경우
            current_sum -= start;
            start++;
        }
        else { // N보다 합이 작은 경우
            end++;
            current_sum += end;
        }
    }

    cout << count << "\n";

    return 0;
}