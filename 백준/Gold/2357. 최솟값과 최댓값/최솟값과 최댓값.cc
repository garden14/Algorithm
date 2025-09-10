#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;
const ll INF = 2e9;

struct SegmentTree{
    int n;
    vector<pair<ll, ll>> tree;

    SegmentTree(const vector<ll>& array) {
        n = array.size();
        int h = (int)ceil(log2(n));
        tree.resize(1 << (h + 1));
        init(array, 1, 0, n - 1);
    }

    void init(const vector<ll>& array, int node, int start, int end) {
        if(start == end) tree[node] = {array[start], array[start]};
        else {
            int mid = (start + end) / 2;
            init(array, node * 2, start, mid);
            init(array, node * 2 + 1, mid + 1, end);
            
            ll min_val = min(tree[node * 2].first, tree[node * 2 + 1].first);
            ll max_val = max(tree[node * 2].second, tree[node * 2 + 1].second);
            tree[node] = {min_val, max_val};
        }
    }

    pair<ll, ll> query(int left, int right, int node, int start, int end){
        if(right < start || left > end) {
            return{INF, 0};
        }
        if(left <= start && end <= right) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        pair<ll ,ll> left_res = query(left, right, node * 2, start, mid);
        pair<ll ,ll> right_res = query(left, right, node * 2 + 1, mid + 1, end);

        ll min_val = min(left_res.first, right_res.first);
        ll max_val = max(left_res.second, right_res.second);

        return {min_val, max_val};
    }

    pair<ll, ll> query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<ll> arr(N);

    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pair<ll, ll> result = st.query(a - 1, b - 1);
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}
