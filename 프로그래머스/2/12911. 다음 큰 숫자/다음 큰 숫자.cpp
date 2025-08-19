#include <string>
#include <vector>
#include <iostream>
using namespace std;

int count_one(int n) {
    int count = 0;
    while(n != 0)
    {
        if (n % 2 == 1) ++count;
        n /= 2; 	
    }
    return count;
}

int solution(int n) {
    int answer = n + 1;
    int origin_count = count_one(n);
    
    while(true) {
        if(count_one(answer) == origin_count) {
            return answer;
        }
        ++answer;
    }
    
    
    return answer;
}