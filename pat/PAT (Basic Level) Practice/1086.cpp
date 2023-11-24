#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int m,n,tol;
int c[maxn][maxn];
vector<pair<int,int>> ans; // (col,row)

map<int,int> mp;
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int main(){
    cin>>m>>n>>tol; // n行m列
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>c[i][j]; 
            mp[c[i][j]] += 1;
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[c[i][j]] > 1) continue;
            int x = i, y = j; bool flag = true;
            for(int k=0;k<8;k++){
                int u = x + dx[k], v = y + dy[k];
                if(u < 1 || u > n || v < 1 || v > m) continue;
                if(abs(c[x][y] - c[u][v]) <= tol){
                    flag = false;
                }
            }
            if(flag) ans.push_back({y,x});
        }
    }
    // for(auto [a,b] : ans) cout << b << " " << a << "\n";
    int sz = ans.size();
    if(sz == 0) cout << "Not Exist" << "\n";
    else if(sz == 1) printf("(%d, %d): %d\n",ans[0].first,ans[0].second,c[ans[0].second][ans[0].first]);
    else cout << "Not Unique" << "\n";
    return 0;
}
