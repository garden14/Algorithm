#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;

void bin(int low, int hi){
	if(low >= hi) return;
	if(low == hi - 1){
		cout << v[low] << "\n";
		return;
	}
    
	int idx = low + 1;
	while(idx < hi){
		if(v[low] < v[idx]) break;
		idx++;
	}
    
	bin(low + 1, idx);
	bin(idx, hi);
    
	cout << v[low] << "\n";
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
    
    int n;

	while(cin >> n){
		v.push_back(n);
	}
    
	bin(0, v.size());
	return 0;
}