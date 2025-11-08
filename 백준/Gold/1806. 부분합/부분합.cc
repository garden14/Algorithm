#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long S; 
    cin >> N >> S;

    vector<int> arr(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }


    int left = 0;
    long long currentSum = 0;
    int minLength = N + 1; 

    for (int right = 0; right < N; ++right) {
        currentSum += arr[right];

        while (currentSum >= S) {
            minLength = min(minLength, right - left + 1);
            
            currentSum -= arr[left];
            ++left;
        }
    }

    if (minLength == N + 1) {
        cout << 0 << "\n"; 
    } else {
        cout << minLength << "\n";
    }

    return 0;
}