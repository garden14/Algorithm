#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int ans = 1e9;
    vector<pair<int,int>> v;

    int n; 
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a, b; 
        cin >> a >> b;
        v.push_back({a, b});
    }


    for(int i = 1; i < (1 << n); ++i){ 
        int a = 1, b = 0;
        for(int x = 0; x < n; ++x){ 
            if(i & (1 << x)){  
                a *= v[x].first;
                b += v[x].second;
            }
        }
        ans = min(ans, abs(a - b));
    }
    
    cout << ans;
    return 0;
}