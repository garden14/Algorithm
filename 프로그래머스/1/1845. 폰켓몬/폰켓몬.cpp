#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> uniqueNums(nums.begin(), nums.end());
    int maxNum = nums.size()/2;

    return min((int)uniqueNums.size(),maxNum);
}