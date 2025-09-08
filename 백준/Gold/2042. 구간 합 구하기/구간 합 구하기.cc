#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// long long으로 자료형 변경
using ll = long long;

struct SegmentTree {
    int n;
    vector<ll> tree;

    SegmentTree(const vector<ll>& array) {
        n = array.size();
        int h = (int)ceil(log2(n));
        tree.resize(1 << (h + 1));
        init(array, 1, 0, n - 1);
    }

    void init(const vector<ll>& array, int node, int start, int end) {
        if (start == end) {
            tree[node] = array[start];
        } else {
            int mid = (start + end) / 2;
            init(array, 2 * node, start, mid);
            init(array, 2 * node + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    ll query(int left, int right, int node, int start, int end) {
        // 범위 밖일 경우
        if (right < start || end < left) {
            return 0; 
        }
        // 범위 안일 경우
        if (left <= start && end <= right) {
            return tree[node];
        }
        // 걸쳐있는 경우
        int mid = (start + end) / 2;
        ll left_sum = query(left, right, node * 2, start, mid);
        ll right_sum = query(left, right, node * 2 + 1, mid + 1, end);
        return left_sum + right_sum; // min을 +로 변경
    }

    ll query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }

    void update(int index, ll newValue, int node, int start, int end) {
        // 범위 밖일 경우
        if (index < start || end < index) {
            return;
        }
        // 리프 노드일 경우
        if (start == end) {
            tree[node] = newValue;
            return;
        }
        // 재귀적으로 업데이트
        int mid = (start + end) / 2;
        update(index, newValue, node * 2, start, mid);
        update(index, newValue, node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; 
    }

    void update(int index, ll newValue) {
        update(index, newValue, 1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    int total_queries = M + K;
    while (total_queries--) {
        int a;
        cin >> a;
        if (a == 1) { // 값 변경
            int b;
            ll c;
            cin >> b >> c;
            st.update(b - 1, c); // 인덱스는 0부터 시작하므로 b-1
        } else if (a == 2) { // 구간 합 출력
            int b, c;
            cin >> b >> c;
            cout << st.query(b - 1, c - 1) << "\n"; // 인덱스는 0부터 시작하므로 b-1, c-1
        }
    }

    return 0;
}