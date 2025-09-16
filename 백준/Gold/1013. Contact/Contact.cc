#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int i = 0; i < T; ++i) {
        string str;
        cin >> str;
        
        regex pattern("(100+1+|01)+");

        if (regex_match(str, pattern))
            cout << "YES\n";

        else
            cout << "NO\n";
    }
}