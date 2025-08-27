#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	string s1, s2; 
	cin >> s1 >> s2; 
	int idx = s2.size() - 1; 
	while (s1.size() < s2.size()) {

		if (s2[idx] == 'A')s2.pop_back(); 
		else {
			s2.pop_back(); 
			reverse(s2.begin(), s2.end()); 
		}
		idx--; 

	}
	if (s1 == s2)cout << 1;
	else cout << 0;  
}