#include <iostream>
#include <deque> 
using namespace std;

deque<int> belt;
deque<int> A; 
int cnt = 0; 
int stage = 0; 

int N, K; 
int main(){
  scanf("%d %d", &N, &K);

  int x;
  for(int i=0; i<N*2; i++){
    scanf("%d", &x);
    A.push_back(x);
    belt.push_back(0);
  }

  while(cnt < K){

    A.push_front(A.back());
    A.pop_back();
    belt.push_front(belt.back());
    belt.pop_back();

    if(belt[N-1] == 1){
      belt[N-1] = 0;
    }


    for(int i = 2 * N; i >= 0; i--){
      if(belt[i] == 1 && A[i + 1] > 0 && belt[i + 1] != 1){
        belt[i+1] = 1;
        belt[i] = 0;
        A[i+1]--;
      }
      if(belt[N-1] == 1){
        belt[N-1] = 0; 
      }
    }


    if(A[0] > 0 && belt[0] == 0){
      belt[0] = 1; 
      A[0]--; 
    }

    int tmp = 0;
    for(int i=0; i<N*2; i++){
      if(A[i] == 0){
        tmp++;
      }
    }
    if(tmp >= K){
      cnt = tmp;
    }

    stage++;
  }

  printf("%d", stage);

  return 0;
}