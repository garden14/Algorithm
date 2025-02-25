#include <iostream>

using namespace std;

long long a, b, c, d;

long long calculate(long long b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a % c;
    }

    d = calculate(b / 2) % c;
    if (b % 2 == 0)
    {
        return d * d % c;
    }
    return d * d % c * a % c;
}

int main()
{
    cin >> a >> b >> c;
    cout << calculate(b);

    return 0;
}