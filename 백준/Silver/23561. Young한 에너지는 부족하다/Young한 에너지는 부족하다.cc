#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	cin >> n;
    
	int* arr = new int[n * 3];

	for (int i = 0; i < n * 3; i++)
		cin >> arr[i];

	sort(arr, arr + n * 3);
	cout << arr[2 * n - 1] - arr[n] << endl;
    
	delete[] arr;
	return 0;
}