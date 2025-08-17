#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N;
    string name;
    cin >> N;

    int cnt = 0;

    for(int i = 666; ; i++) {
        name = to_string(i);

        if(name.find("666") != -1) {
            cnt++;
            if(cnt == N) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}