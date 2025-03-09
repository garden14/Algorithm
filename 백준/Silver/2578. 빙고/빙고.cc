#include <bits/stdc++.h>
 
using namespace std;
 
int bingo[5][5];
int vis[5][5];
 
int check1() {
    int ret = 0;
    
    for(int i = 0; i < 5; i++)
        if(vis[i][0] && vis[i][1] && vis[i][2] && vis[i][3] && vis[i][4])
            ret++;
            
    return ret;
}
 
int check2() {
    int ret = 0;
    
    for(int i = 0; i < 5; i++)
        if(vis[0][i] && vis[1][i] && vis[2][i] && vis[3][i] && vis[4][i])
            ret++;
            
    return ret;
}
 
int check3() {
    int ret = 0;
    
    if(vis[0][0] && vis[1][1] && vis[2][2] && vis[3][3] && vis[4][4])
        ret++;
        
    return ret;
}
 
int check4() {
    int ret = 0;
    
    if(vis[0][4] && vis[1][3] && vis[2][2] && vis[3][1] && vis[4][0])
        ret++;
        
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
        }
    }
    
    for(int k = 0; k < 25; k++) {
        int a;
        cin >> a;
        
        int bingoCnt = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(bingo[i][j] == a)
                    vis[i][j] = true;
            }
        }
        
        bingoCnt += check1();
        bingoCnt += check2();
        bingoCnt += check3();
        bingoCnt += check4();
        
        if(bingoCnt >= 3) {
            cout << k+1;
            return 0;
        }
    }
}