#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    int q, start, end;
    int counts[27][200001];
    char letter;

    cin >> S >> q;
    counts[S[0] - 'a'][0] = 1;
    
    for (int i = 1; i < S.size(); ++i)
    {
        for (int j = 0; j < 27; ++j)
        {
            counts[j][i] = counts[j][i - 1];
        }
        counts[S[i] - 'a'][i]++;
    }
    
    for (int i = 0; i < q; ++i)
    {
        cin >> letter >> start >> end;
        int temp = letter - 'a';
        if (start == 0)
            cout << counts[letter - 'a'][end] << '\n';
        else
            cout << counts[letter - 'a'][end] - counts[letter - 'a'][start - 1] << '\n';
    }

    return 0;
}