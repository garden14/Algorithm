#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,int>> node[10002];
bool isVisited[10002] = {false,};
int result = 0;
int endPoint = 0;

void dfs(int p, int len){
  if(isVisited[p]) return;
  
  isVisited[p] = true;
  if(result < len){
    result = len;
    endPoint = p;
  }
  
  for(int i = 0; i < node[p].size(); ++i){
    dfs(node[p][i].first, len + node[p][i].second);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); 
  cout.tie(NULL);
  
  int N;
  cin >> N;
  
  for(int i = 0; i < N - 1; ++i){
    int A, B, C;
    cin >> A >> B >> C;
    node[A].push_back({B, C});
    node[B].push_back({A, C});
  }
  
  dfs(1,0); 
  
  result = 0;
  memset(isVisited, false, sizeof(isVisited));
  
  dfs(endPoint, 0); 
  cout << result;
}