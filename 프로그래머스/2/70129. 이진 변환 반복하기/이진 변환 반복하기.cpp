#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

string toBinary(int n) {
    if(n == 0 ) return "0";
    
    string binary = "";
    
    while(n > 0) {
        binary += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

vector<int> solution(string s) {
    vector<int> answer;
    int trans_count = 0;
    int zero_count = 0;
    
    while(s != "1") {
        trans_count++;
        
        int one_count = 0;
        
        for(char c : s) {
            if(c == '1') {
                one_count++;
            } else { zero_count++; }
        }
        
        s = toBinary(one_count);
    }
    
    answer.push_back(trans_count);
    answer.push_back(zero_count);
    
    return answer;
}