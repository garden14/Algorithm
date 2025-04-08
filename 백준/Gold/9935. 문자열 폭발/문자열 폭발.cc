#include <iostream>
#include <string>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1;
    cin >> s2;

    string result;

    for (int i = 0; i < s1.length(); i++)
    {
        result += s1[i];
        if (result.length() >= s2.length())
        {
            if (result.substr(result.length() - s2.length(), s2.length()) == s2)
            {
                result.erase(result.length() - s2.length(), result.length());
            }
        }
    }
    if (result.length())
        cout << result;
    else
        cout << "FRULA";

    return 0;
}