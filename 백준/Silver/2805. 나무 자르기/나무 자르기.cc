#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M; // M은 20억까지 가능하므로 long long
    cin >> N >> M;

    vector<int> trees(N);
    long long max_height = 0;
    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
        if (trees[i] > max_height) {
            max_height = trees[i];
        }
    }

    // 이분 탐색을 위한 시작점, 끝점, 결과 변수 설정
    long long low = 0;
    long long high = max_height;
    long long result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2; // 중간 높이(절단기 높이 후보)
        long long total_wood = 0;

        // mid 높이로 잘랐을 때 얻는 나무의 총 길이 계산
        for (int i = 0; i < N; ++i) {
            if (trees[i] > mid) {
                total_wood += trees[i] - mid;
            }
        }

        // 1. 얻은 나무가 목표(M)보다 많거나 같은 경우
        if (total_wood >= M) {
            result = mid; // 현재 높이는 정답이 될 수 있음 (일단 저장)
            low = mid + 1; // 더 높은 높이로도 가능한지 탐색하기 위해 시작점 이동
        }
        // 2. 얻은 나무가 목표(M)보다 적은 경우
        else {
            high = mid - 1; // 높이가 너무 높으므로, 끝점을 낮춰서 더 낮은 높이 탐색
        }
    }

    cout << result << "\n";

    return 0;
}