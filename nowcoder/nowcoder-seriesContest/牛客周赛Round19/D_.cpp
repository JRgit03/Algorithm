#include <bits/stdc++.h>
using namespace std;

int maybe;
int X[4][4]; //在合法情况下 点[x,y]为X的次数
int O[4][4];

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

vector<string> g(4),t;

int main(){
    for(int i=0;i<4;i++) cin>>g[i];
    for(int i=0;i<(1<<16);i++){
        vector<int> b(16); int ok = 1;
        for(int j=0;j<16;j++) {
            int x = j / 4 , y = j % 4;
            if(((i >> j) & 1) && g[x][y] >= '0' && g[x][y] <= '8') ok = 0;
            b[j] = (i >> j) & 1;
        }
        if(!ok) continue;
        t = g;
        for(int j=0;j<16;j++) {
            int x = j / 4 , y = j % 4;
            if(t[x][y] >= '0' && t[x][y] <= '8') continue;
            t[x][y] = b[j] ? 'X' : 'O';
        }
        bool flag = true;
        for(int x=0;x<4;x++){
            for(int y=0;y<4;y++){
                if(t[x][y] >= '0' && t[x][y] <= '8'){
                    int cnt = 0;
                    for(int k=0;k<8;k++){
                        int u = x + dx[k], v = y + dy[k];
                        if(u < 0 || u >= 4 || v < 0 || v >= 4) continue;
                        if(t[u][v] == 'X') cnt++;
                    }
                    if(cnt != t[x][y] - '0') flag = false;
                }
            }
        }
        if(flag){
            maybe++;
            for(int j=0;j<16;j++) {
                if(b[j]) X[j/4][j%4]++;
                else O[j/4][j%4]++;
            }
        }
    }
    // cout << maybe << "\n";
    for(int x=0;x<4;x++){
        for(int y=0;y<4;y++){
            if(g[x][y] >= '0' && g[x][y] <= '8') cout << g[x][y];
            else if(X[x][y] == maybe) cout << "X";
            else if(O[x][y] == maybe) cout << "O";
            else cout << ".";
        }
        cout << "\n";
    }
    return 0;
}

// 如果一个格子在所有合法情况都是雷，那么它一定是雷，
// 如果都不是雷，那么它一定不是雷，剩下的未知。
