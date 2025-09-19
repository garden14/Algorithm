#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> c;
    
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        x.push_back(a);
    }
    
    sort(x.begin(),x.end());

    int start = 0;
    int end = x[n-1];
    int result = 0;
    int temp, count;

    while(start <= end) {
        int mid = (start + end) / 2;
        temp = 0, count = 1;
        for(int i =1;i < n; ++i) {
            if(x[i] - x[temp] >= mid) {
                temp = i;
                count++;
            }
        }

        if(count >= c) {
            result = mid;
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    cout << result;
}
