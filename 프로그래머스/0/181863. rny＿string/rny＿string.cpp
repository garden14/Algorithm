#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    if (rny_string.find("m") == string::npos) {
        return rny_string;
    } else {
        string answer = "";
        for (int i = 0; i < rny_string.length(); i++) {
            char s = rny_string[i];
            if (s == 'm') {
                answer.append("rn");
            } else {
                answer += s;
            }
        }
        return answer;
    }
}