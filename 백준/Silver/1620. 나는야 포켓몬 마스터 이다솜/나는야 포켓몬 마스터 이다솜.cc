#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<string,string> name_to_num;
    unordered_map<string,string> num_to_name;

    

    for(int i=1; i<=n; i++) {
        string name;
        cin >> name;
        string num_str = to_string(i);
        name_to_num[name] = num_str;
        num_to_name[num_str] = name;
    }

    for(int j=0; j<m; j++) {
        string cmd;
        cin >> cmd;

        if(num_to_name.find(cmd) != num_to_name.end()) {
            cout << num_to_name[cmd] << '\n';
        }else {
            cout << name_to_num[cmd] << '\n';
        }

    }

    return 0;
}