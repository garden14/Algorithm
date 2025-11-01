#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    int n = S.length();
    unordered_set<string> distinct;

    for (int i = 0; i < n; ++i) { 
        for (int j = 1; i + j <= n; ++j) { 
            distinct.insert(S.substr(i, j));
        }
    }

    cout << distinct.size() << "\n";

    return 0;
}