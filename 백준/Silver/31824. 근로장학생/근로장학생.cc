#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Word {
    string eng, kor;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Word> dict(n);

    for (int i = 0; i < n; ++i) {
        cin >> dict[i].eng >> dict[i].kor;
    }

    sort(dict.begin(), dict.end(), [](const Word& a, const Word& b) {
        return a.eng < b.eng;
    });

    cin.ignore(); 
    for (int i = 0; i < m; ++i) {
        string s;
        getline(cin, s);
        string answer = "";

        for (int pos = 0; pos < (int)s.size(); ++pos) {
            vector<pair<int, string>> found;
            for (const auto& d : dict) {
                int len = d.eng.size();
                if (pos + len <= (int)s.size() && s.substr(pos, len) == d.eng) {
                    found.emplace_back(len, d.kor);
                }
            }
            for (const auto& f : found) {
                answer += f.second;
            }
        }
        if (answer.empty()) cout << -1 << '\n';
        else cout << answer << '\n';
    }
    return 0;
}
