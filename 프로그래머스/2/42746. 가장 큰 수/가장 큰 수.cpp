#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    string aa = to_string(a);
    string bb = to_string(b);
    return aa+bb > bb+aa;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(),cmp);

    if(numbers[0] == 0) {
        return "0";
    }

    string answer = "";

    for(int i: numbers) {
        answer += to_string(i);
    }
    return answer;
}