#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

struct SegmentTree{
    int n;
    vector<ll> tree;

    SegmentTree(const vector<ll>& array) {
        n = array.size();
        int h = (int)ceil(log2(n));
        tree.resize(1<<(h+1));
        init(array, 1, 0, n - 1);
    }

    void init(const vector<ll>& array, int node, int start, int end) {
        if(start == end){
            tree[node] = array[start];
        }
        else {
            int mid = (start + end) / 2;
            init(array, node * 2, start, mid);
            init(array, node * 2 + 1, mid + 1, end);
            tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
        }
    }

    ll query(int left, int right, int node, int start, int end) {
        if(right < start || left > end){
            return 1;
        }

        if(left <= start && end <= right) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        ll left_multiple = query(left, right, node * 2, start, mid);
        ll right_multiple = query(left, right, node * 2 + 1, mid + 1, end);

        return (left_multiple * right_multiple) % 1000000007;
    }

    ll query(int left, int right){
        return query(left, right, 1, 0, n - 1);
    }

    void update(int index, ll newValue, int node, int start, int end) {
        if(index < start || end < index){
            return;
        }

        if(start == end) {
            tree[node] = newValue;
            return;
        }

        int mid = (start + end) / 2;
        update(index, newValue, node * 2, start, mid);
        update(index, newValue, node * 2 + 1, mid + 1, end);
        
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
    }

    void update(int index, ll newValue){
        update(index, newValue, 1, 0, n - 1);
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> arr(N);
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    SegmentTree st(arr);

    int total_queries(M + K);

    while(total_queries--) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            ll c;
            cin >> b >> c;
            st.update(b - 1, c);
        } else if (a == 2) { 
            int b, c;
            cin >> b >> c;
            cout << st.query(b - 1, c - 1) << "\n";
        }
    
    }


    return 0;
}