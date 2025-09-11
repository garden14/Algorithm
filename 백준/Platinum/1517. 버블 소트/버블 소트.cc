#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

struct SegmentTree
{
    int n;
    vector<ll> tree;

    SegmentTree(const vector<ll>& array) {
        n = array.size();
        int h = (int)ceil(log2(n));
        tree.resize(1 << (h + 1));
        init(array, 1, 0, n - 1);
    }

    void init(const vector<ll>& array, int node, int start, int end) {
        if(start == end) {tree[node] = array[start];}
        else {
            int mid = (start + end) / 2;
            init(array, node * 2, start, mid);
            init(array, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    ll query(int left, int right, int node, int start, int end) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        ll left_sum = query(left, right, node * 2, start, mid);
        ll right_sum = query(left, right, node * 2 + 1, mid + 1, end);
        return left_sum + right_sum;
    }

    ll query(int left, int right) {
        return query(left, right, 1, 0 , n - 1);
    }

    void update(int index, ll newValue, int node, int start, int end) {
        if (index < start || end < index) return;
        if (start == end) {
            tree[node] = newValue; 
            return;
        } 

        int mid = (start + end) / 2;
        if (index <= mid) {
            update(index, newValue, node * 2, start, mid);
        } else {
            update(index, newValue, node * 2 + 1, mid + 1, end);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int index, int newValue) {
        update(index, newValue, 1, 0, n - 1);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> arr(N);
    for(int i = 0; i < N; ++i) {
        cin >> arr[i].first;  
        arr[i].second = i;    
    }

    sort(arr.begin(), arr.end());

    vector<ll> initial_indices(N, 1);
    SegmentTree st(initial_indices);

    ll ans = 0;

    for(int i = 0; i < N; ++i) {
        int original_idx = arr[i].second;
        ans += st.query(0, original_idx - 1);
        st.update(original_idx, 0);
    }

    cout << ans << "\n";

    return 0;
}