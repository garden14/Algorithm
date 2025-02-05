#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer(start_num- end_num+1);
    int j =0;
    for(int i = start_num; i>= end_num; i--) {
        answer[j] = i;
        j++;
    }
    return answer;
}