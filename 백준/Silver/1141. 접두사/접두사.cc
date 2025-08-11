#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> arr(N);

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int result = 0;

    for(int i = 0; i < N; i++) {
        bool is_prefix = false;

        for(int j = i + 1; j < N; j++) {
            if(arr[j].find(arr[i]) == 0) {
                is_prefix = true;
                break;
            }
        }

        if(!is_prefix) result++;
    }
    
    cout << result;

    return 0;
}