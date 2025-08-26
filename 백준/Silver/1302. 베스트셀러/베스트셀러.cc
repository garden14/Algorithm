#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<string, int> book;
    int len, max_count = 0; 
    string res = "", str;
    cin >> len;

    for (int i = 0; i < len; ++i) {
        cin >> str;
        book[str]++; 
    }

    for (auto b : book){
        if (b.second > max_count)
        {
            max_count = b.second;
            res = b.first;
        }
    }
    cout << res;
}