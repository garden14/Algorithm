#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int A, B;
	int ans = -1;
	queue<pair<long long int,int> > q;
	
	cin >> A >> B;
	
	q.push(make_pair(A,1));
	
	while(!q.empty()){
		long long int k = q.front().first;
		int n = q.front().second;
		q.pop();
		
		if(k == B){
			ans = n;
			break;
		}
		
		if(k * 2 <= B)
			q.push(make_pair(k * 2, n + 1));
		if(k * 10 + 1 <= B)
			q.push(make_pair(k * 10 + 1, n + 1));
	}
	
    cout << ans;
    
	return 0;
}