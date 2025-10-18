#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y; 
    cin >> x >> y;

    long long diff = y - x;

    if (diff == 0) {
        cout << 0 << "\n";
        return 0; 
    }

    long long n = (long long)(sqrt(diff));

    if (n * n == diff) {
        cout << 2 * n - 1 << "\n";
    }
    else {
        long long remainder = diff - (n * n);
        
        if (remainder <= n) {
            cout << 2 * n << "\n";
        }
        else {
            cout << 2 * n + 1 << "\n";
        }
    }

    return 0;
}