#include<iostream>
#include<vector>

using namespace std;

float A, B; 
int sosu[] = { 2,3,5,7,11,13,17 }; 
float dp[19][19][19]; 
float play_game(int round, int a, int b) {

	if (round == 18) {
		for (int x : sosu) {
			if (a == x || b == x) {
				return 1;
			}
		}
		return 0;
	}
	if (dp[round][a][b]) return dp[round][a][b];

	dp[round][a][b] += play_game(round + 1, a + 1, b + 1) * A * B;
	dp[round][a][b] += play_game(round + 1, a + 1, b) * A * (1 - B);
	dp[round][a][b] += play_game(round + 1, a, b + 1) * (1-A) * B;
	dp[round][a][b] += play_game(round + 1, a, b) * (1 - A) * (1 - B);

	return dp[round][a][b];
}

int main() {

	cin >> A >> B;
	A /= 100;
	B /= 100;

	cout << play_game(0, 0, 0);

	return 0;
}