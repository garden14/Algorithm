#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string L, R;
    int cnt = 0;

    cin >> L >> R;

    if(L.length() != R.length()) cnt = 0;

    else{
        for(int i = 0; i<L.length(); i++) {
            if(L[i] != R[i]){
                break;
            }
            if(L[i] == '8'){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}