#include<iostream>
using namespace std;
 
const int MAX = 1000000; 
int Prime[MAX]; 
int pn = 0; 
bool check[MAX + 1]; 
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int T; 
	cin >> T;
 
	for (int i = 2; i <= MAX; i++)
	{
		if (check[i] == false)
		{
			Prime[pn++] = i; 
			for (int k = i + i; k <= MAX; k += i) 
			{
				check[k] = true; 
			}
		}
	}
 
	while (T--)
	{
		int N;
		cin >> N;
		int cnt = 0; 
 
		for (int i = 0; i < pn; i++)
		{
			if (Prime[i] <= N - Prime[i] && check[N - Prime[i]] == false)
			{
				cnt += 1;
			}
 
		}
		cout << cnt << '\n';
	}
	return 0;
}