#include <iostream>

int arr[3];
int dp_min[3] = {0,};
int dp_max[3] = {0,};

using namespace std;

int fmin(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int fmax(int a, int b)
{
    if (a < b)
        return b;
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int temp0, temp1, temp2 = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        temp0 = dp_min[0];
        temp1 = dp_min[1];
        temp2 = dp_min[2];

        dp_min[0] = fmin(temp0, temp1) + arr[0];
        dp_min[1] = fmin(fmin(temp0, temp1), temp2) + arr[1];
        dp_min[2] = fmin(temp1, temp2) + arr[2];

        temp0 = dp_max[0];
        temp1 = dp_max[1];
        temp2 = dp_max[2];

        dp_max[0] = fmax(temp0, temp1) + arr[0];
        dp_max[1] = fmax(fmax(temp0, temp1), temp2) + arr[1];
        dp_max[2] = fmax(temp1, temp2) + arr[2];
    }
        cout << fmax(fmax(dp_max[0],dp_max[1]),dp_max[2]) << " " << fmin(fmin(dp_min[0],dp_min[1]),dp_min[2]);

    return 0;
}