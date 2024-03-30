#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 22;
set<int> ans;
int vis[N][N][N];

void solve(){
    int ma,mb,mc; cin>>ma>>mb>>mc;
    queue<array<int,3>> q;
    q.push({0,0,mc});
    vis[0][0][mc] = 1;
    while(q.size()){
        auto [x1,y1,z1] = q.front(); q.pop();
        if(x1 == 0) ans.insert(z1);
        int x2,y2,z2,c;
        auto check = [&](){
            // cout << x2 << " " << y2 << " " << z2 << "\n";
            if(!vis[x2][y2][z2]){
                vis[x2][y2][z2] = 1;
                q.push({x2,y2,z2});
            }
        };
        // A->B
        c = min(x1, mb - y1);
        x2 = x1 - c, y2 = y1 + c, z2 = z1;
        check();
        // A->C
        c = min(x1, mc - z1);
        x2 = x1 - c, y2 = y1 , z2 = z1 + c;
        check();
        // B->C
        c = min(y1, mc - z1);
        x2 = x1, y2 = y1 - c, z2 = z1 + c;
        check();
        // B->A
        c = min(y1, ma - x1);
        x2 = x1 + c, y2 = y1 - c, z2 = z1;
        check();
        // C->A
        c = min(z1, ma - x1);
        x2 = x1 + c, y2 = y1, z2 = z1 - c;
        check();
        // C->B
        c = min(z1, mb - y1);
        x2 = x1, y2 = y1 + c, z2 = z1 - c;
        check();
    }
    for(auto &x : ans) cout << x << " ";
}

signed main(){
    solve();
    return 0;
}
