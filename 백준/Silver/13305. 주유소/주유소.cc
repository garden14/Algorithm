#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0); 
    cout.tie(0);
    int N; 
    cin >> N;
    
    long long* distance = new long long[N - 1]; 
    for (int i = 0; i < N - 1; i++) {
        cin >> distance[i];
    }

    long long* cost = new long long[N]; 
    for (int j = 0; j < N; ++j) {
        cin >> cost[j];
    }

    long long total = 0;
    for (int k = 0; k < N-1; ++k) {
        if (cost[k] < cost[k+1]) {
            cost[k+1] = cost[k];
        }
        total += cost[k] * distance[k];
    }
    cout << total;
    return 0;
}