#include <bits/stdc++.h>
using namespace std;

string str = " dfs";
char g[3][3], back[3][3];

int main(){
    for(int i=0;i<3;i++) cin>>g[i];
    int ans = 9, up = 1;
    for(int i=0;i<9;i++) up *= 4; //262144
    auto check = [&](){
        int cnt1 = 0, cnt2 = 0; string s = "";
        for(int i=0;i<3;i++){
            s = ""; s += back[i][0]; s += back[i][1]; s += back[i][2];
            if(s == "dfs") cnt1 += 1;
        }
        for(int i=0;i<3;i++){
            s = ""; s += back[0][i];  s += back[1][i]; s += back[2][i]; 
            if(s == "dfs") cnt2 += 1;
        }
        return cnt1 == 1 && cnt2 == 1;
    };
    for(int i=0;i<up;i++){
        int op = 0, c = i;
        memcpy(back, g, sizeof g);
        for(int j=0;j<9;j++){
            int v = c % 4; c /= 4;
            int x = j / 3, y = j % 3;
            if(v && back[x][y] != str[v]) {
                op += 1;
                back[x][y] = str[v];
            }
        }
        if(check()) ans = min(ans, op);
    }
    cout << ans << "\n";
    return 0;
}
