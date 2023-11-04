#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n,m,k;
string s;
int vis[N][N];
int f[N][N];

void solve(){
    cin>>n>>m>>k;
    cin>>s; 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)   
            f[i][j] = vis[i][j] = 0;
    int L = 1, R = m, U = 1, D = n;
    // 模拟边界移动 移动图 反向
    int l = 1, r = m, u = 1, d = n;
    for(auto op : s){
        if(op == 'U') u++,d++;
        else if(op == 'D')u--,d--;
        else if(op == 'L')l++,r++;
        else if(op == 'R')l--,r--;
        L = max(L,l);
        R = min(R,r);
        U = max(U,u);
        D = min(D,d);
    } 
    // 不存在袋鼠存留
    if(L > R || U > D){
        if(k == 0) cout << n * m << "\n";
        else cout << 0 << "\n";
        return;
    }
    int ne = (R-L+1) * (D-U+1) - k;
    if(ne < 0){
        cout << 0 << "\n";
        return;
    }
    int x1 = U, y1 = L, x2 = D, y2 = R;
    // 移动存留袋鼠矩形
    auto add = [&](int x1,int y1,int x2,int y2){
        if(!vis[x1][y1]){
            vis[x1][y1] = 1;
            f[x1][y1] += 1;
            f[x2+1][y1] -= 1;
            f[x1][y2+1] -= 1;
            f[x2+1][y2+1] += 1; 
        }
    };
    add(x1,y1,x2,y2);
    // 正向
    for(auto op : s){
        if(op == 'L') y1--,y2--;
        else if(op == 'R')y1++,y2++;
        else if(op == 'U')x1--,x2--;
        else if(op == 'D')x1++,x2++;
        add(x1,y1,x2,y2);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(f[i][j] == ne) 
                ans++;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
