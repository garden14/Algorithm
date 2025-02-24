#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<string, string, greater<string>> record;

    string name, rec;

    for(int i=0; i<n; i++) {
        cin >> name >> rec;
        if(rec == "enter") {
            record.insert(make_pair(name, rec));
        }
        else {
            record.erase(name);
        }
    }


    for(auto iter : record) {
        cout << iter.first << "\n";
    }

    return 0;
}