#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> NGE(N, -1);

    stack<int> s;

    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for(int i = 0; i < N; ++i) {
        while(!s.empty() && A[s.top()] < A[i]) {
            NGE[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < N; ++i) {
        cout << NGE[i] << " ";
    }

    return 0;
}