#include <iostream> 
#include <vector> 
#include <string> 
#include <iomanip>

using namespace std;

string digits[10][5] = {
    {"###", "#.#", "#.#", "#.#", "###"}, 
    {"..#", "..#", "..#", "..#", "..#"}, 
    {"###", "..#", "###", "#..", "###"}, 
    {"###", "..#", "###", "..#", "###"}, 
    {"#.#", "#.#", "###", "..#", "..#"}, 
    {"###", "#..", "###", "..#", "###"}, 
    {"###", "#..", "###", "#.#", "###"}, 
    {"###", "..#", "..#", "..#", "..#"}, 
    {"###", "#.#", "###", "#.#", "###"}, 
    {"###", "#.#", "###", "..#", "###"}  
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> grid(5);
    for (int r = 0; r < 5; ++r) cin >> grid[r];

    vector<vector<int>> cand(N);
    for (int i = 0; i < N; ++i) {
        vector<string> block(5);
        for (int r = 0; r < 5; ++r) block[r] = grid[r].substr(i * 4, 3);

        for (int d = 0; d < 10; ++d) {
            bool ok = true;
            for (int r = 0; r < 5 && ok; ++r)
                for (int c = 0; c < 3; ++c)
                    if (block[r][c] == '#' && digits[d][r][c] == '.') {
                        ok = false; break;
                    }
            if (ok) cand[i].push_back(d);
        }
        if (cand[i].empty()) { 
            cout << -1 << '\n';
            return 0;
        }
    }

    long double total_cnt = 1.0L;
    vector<long double> sum_digits(N, 0.0L);
    for (int i = 0; i < N; ++i) {
        total_cnt *= (long double)cand[i].size();
        for (int d : cand[i]) sum_digits[i] += d;
    }

    vector<long double> weight(N);
    weight[N - 1] = 1.0L;
    for (int i = N - 2; i >= 0; --i) weight[i] = weight[i + 1] * 10.0L;

    long double total_sum = 0.0L;
    for (int i = 0; i < N; ++i) {
        long double others = total_cnt / (long double)cand[i].size(); 
        total_sum += sum_digits[i] * weight[i] * others;
    }

    long double ans = total_sum / total_cnt;

    cout << fixed << setprecision(10) << (double)ans << '\n';
    return 0;
}
