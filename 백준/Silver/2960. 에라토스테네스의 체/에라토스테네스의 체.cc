#include <iostream>

int main()
{
	using namespace std;
	int num[1000] = { 0, }; 

	int N, K, cnt;
	cin >> N >> K;

	int erase = 0;
	for (int i = 2; i <= N; i++)
		for (int j = i; j <= N; j = j + i)
		{

			cnt = 0;
			for (int x = 0; num[x] != 0; x++)
			{
				if (num[x] == j)
					cnt++; 
			}
			if(cnt==0)
				num[erase++] = j;
		}
	cout << num[K - 1] << endl; 

	return 0;
}