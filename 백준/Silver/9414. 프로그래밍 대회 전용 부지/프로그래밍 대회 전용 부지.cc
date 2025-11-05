#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX = 5000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        vector<int> price;
        int cmd = 1;

        while(cin >> cmd && cmd != 0) {
            price.push_back(cmd);
        }

        sort(price.begin(), price.end(), greater<int>());
        
        long long total = 0;
        bool expensive = false;

        for(int i = 0; i < price.size(); ++i) {
            long long term = 2;

            for(int j = 0; j < i + 1; ++j) {
                term *= price[i];

                if(term > MAX) {
                    expensive = true;
                    break;
                }
            }

            if(expensive) break;
            total += term;

            if(total > MAX) {
                expensive = true;
                break;
            }
        }

        if(expensive) {
            cout << "Too expensive\n";
        }else {
            cout << total << "\n";
        }
    }

    return 0;
}