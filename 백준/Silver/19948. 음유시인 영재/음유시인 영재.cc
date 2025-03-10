#include <iostream>
#include <vector>
#include<cctype>
#include<string>
using namespace std;

int space;
int alpha[26];
vector<char> ans;

int main() {
    string str;
    getline(cin, str);

    cin >> space;
    for (int i = 0; i < 26; i++) {
        cin >> alpha[i];
    }
    ans.push_back(tolower(str[0])); 
    for(int i=1; i<str.size();i++){
        if(isalpha(str[i]) && str[i-1]==' '){
            ans.push_back(tolower(str[i]));
        }
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == str[i+1]) continue; 

        if (str[i] == ' ') { 
            if (space <= 0) { 
                cout << -1;
                return 0;
            }
            else { 
                space--; 
            }
        }
        else { 
            if (isupper(str[i])) { 
                str[i] = str[i] + 32; 
            }
            int tmp = str[i] - 97; 

            if (alpha[tmp] <= 0) {
                cout << -1; 
                return 0;
            } else {
                alpha[tmp]--; 
            }
        }
    }

    for(int i=0; i<ans.size();i++){
        if(alpha[ans[i]-97] >=1) {
            cout << char(toupper(ans[i]));
            alpha[ans[i]-97]--;
        }
        else{
            cout << -1;
            return 0;
        }
    }
}