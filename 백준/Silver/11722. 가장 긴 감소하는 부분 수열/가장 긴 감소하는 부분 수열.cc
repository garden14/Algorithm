#include <iostream>
#include <algorithm>
using namespace std;

int N, sum;
int A[1001];
int dp[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> A[i];
	
	for(int i=0; i<N; i++) {
		dp[i] = 1;					
		
		for(int j=0; j<i; j++) {			
			if( A[i] < A[j] ) {			
				dp[i] = max(dp[i], dp[j]+1);	
			}
		}
		sum = max(sum, dp[i]);				
	}
	cout << sum;
}