#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y)
{
    vector<int> countX(10, 0), countY(10, 0);

    for (char ch : X)
        countX[ch - '0']++;
    for (char ch : Y)
        countY[ch - '0']++;

    string answer = "";

    for (int i = 9; i >= 0; i--)
    {
        int count = min(countX[i], countY[i]);
        answer += string(count, '0' + i);
    }

    if (answer.empty())
        return "-1";
    if (answer[0] == '0')
        return "0";

    return answer;
}
