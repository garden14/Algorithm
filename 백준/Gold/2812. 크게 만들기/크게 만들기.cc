#include <iostream>
#include <string>
#include <deque> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string number;
    cin >> number;

    deque<char> dq;
    int k_to_remove = k; 

    for (int i = 0; i < n; i++) {
        char current_digit = number[i];

        while (!dq.empty() && k_to_remove > 0 && dq.back() < current_digit) {
            dq.pop_back();
            k_to_remove--; 
        }

        dq.push_back(current_digit);
    }

    for (int i = 0; i < n - k; i++) {
        cout << dq[i];
    }
    cout << '\n';

    return 0;
}