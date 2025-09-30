#include <iostream>

using namespace std;

int S[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    string str;
    int x;
    for(int i = 0; i < M; ++i) {
        cin >> str;

        if(str == "add") {
            cin >> x;
            S[x] = 1;
        }else if(str == "remove") {
            cin >> x;
            S[x] = 0;
        }else if(str == "check") {
            cin >> x;
            if(S[x] == 1) {
                cout << 1 << "\n";
            } else {cout << 0 << "\n";}
        }else if(str == "toggle") {
            cin >> x;
            if(S[x] == 1) {
                S[x] = 0;
            } else {S[x] = 1;}
        }else if(str == "all") {
            for(int i = 1; i <= 20; ++i) {
                S[i] = 1;
            }
        }else {
            for(int i = 1; i <= 20; ++i) {
                S[i] = 0;
            }
        }
    }


    return 0;
}