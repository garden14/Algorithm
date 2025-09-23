#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, B, C;
    cin >> N;

    vector <int> A(N);

    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cin >> B >> C;

    long long result = N;

    for(int i = 0; i < N; ++i) {
        A[i] -= B;
        if(A[i] < 0) continue;
        result += A[i] / C;
        if(A[i] % C) result += 1;
    }

    cout << result;
    return 0;
}