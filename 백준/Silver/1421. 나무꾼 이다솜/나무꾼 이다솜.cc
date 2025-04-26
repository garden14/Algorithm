#include <iostream>
#include <vector>
 
using namespace std;
 
int n, c, w;
vector<int> vec;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> c >> w;
 
    long long temp = 0;
    long long max_num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vec.push_back(temp);
        max_num = max(max_num, temp);
    }
 
    long long ans = 0;
 
    for (int i = 1; i <= max_num; i++)
    {
        long long result = 0;
 
        for (int j = 0; j < n; j++)
        {
            if (i == vec[j])
            {
                result += i * w;
            }
            else if (i < vec[j])
            {
                int t = vec[j] % i == 0 ? -1 : 0;
                if (((vec[j] / i) + t) * c < (i * w) * (vec[j] / i))
                {
                    result -= ((vec[j] / i) + t) * c;
                    result += (i * w) * (vec[j] / i);
                }
            }
        }
 
        ans = max(ans, result);
    }
 
    cout << ans;
 
    return 0;
}