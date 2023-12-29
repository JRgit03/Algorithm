#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> ans;
string g[4];

int main(){
    for(int i=0;i<4;i++) cin>>g[i];
    for(int i=0;i<(1<<16);i++){
        int f[4][4]; memset(f,0,sizeof f);
        vector<pair<int,int>> tmp;
        for(int j=0;j<16;j++) if((i >> j) & 1){
            int x = j / 4 , y = j % 4;
            tmp.push_back({x+1,y+1});
            for(int k=0;k<4;k++) f[x][k] += 1;
            for(int k=0;k<4;k++) f[k][y] += 1;
            f[x][y] -= 1;
        }
        bool suc = true;
        for(int v1=0;v1<4;v1++){
            for(int v2=0;v2<4;v2++){
                if(f[v1][v2] & 1){
                    char c = g[v1][v2];
                    if(c == '-') suc = false;
                }else{
                    if(c == '+') suc = false;
                }
            }
        }
        if(!suc) continue;
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end(), [&](auto &p, auto q){
        return (p.size() != q.size() ? p.size() < q.size() : p < q);
    });
    cout << ans[0].size() << "\n";
    for(auto [x,y] : ans[0]) cout << x << " " << y << "\n";
    return 0;
}
