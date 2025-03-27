#include <iostream>
#include <vector>

using namespace std;

bool calcul(string a, string b)
{
    vector<int> va(26, 0), vb(26, 0);
    string sa = "", sb = "";
    int cnta = 1, cntb = 1;

    for (int i = 0; i < a.size(); i++)
    {
        int n = a[i] - 'a';
        if (!va[n])
            va[n] = cnta++;
        sa += (va[n] + '0');
    }

    for (int i = 0; i < b.size(); i++)
    {
        int n = b[i] - 'a';
        if (!vb[n])
            vb[n] = cntb++;
        sb += (vb[n] + '0');
    }

    if (sa == sb)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<string> shome(N);

    for (int i = 0; i < N; i++)
    {
        cin >> shome[i];
    }

    int cnt = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (calcul(shome[i], shome[j]))
            {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}