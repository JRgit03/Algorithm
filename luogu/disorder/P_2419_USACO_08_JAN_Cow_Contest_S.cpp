#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 110 , INF = 0x3f3f3f3f;
int n,m;
int f[N][N];

//floyd 传递闭包
void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        f[u][v] = 1;
    }

    for(int k=1;k<=n;k++) //floyd第一层放k
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j] |= (f[i][k] & f[k][j]);
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        int flag = 1;
        for(int j=1;j<=n;j++)
            if(i == j) continue;
            else flag &= (f[i][j] | f[j][i]);
        ans += flag;
    }
    cout << ans << "\n";
}

// 正向 + 反向
int d[N][N];
int st[N];
// 正向
int dfs1(int u){
    int res = 1; st[u] = 1;
    for(int i=1;i<=n;i++)
        if(d[u][i] && !st[i])
            res += dfs1(i);
    return res;
}

// 反向
int dfs2(int u){
    int res = 1; st[u] = 1;
    for(int i=1;i<=n;i++)
        if(d[i][u] && !st[i])
            res += dfs2(i);
    return res;
}

void solve2(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        d[u][v] = 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        memset(st,0,sizeof st);
        if(dfs1(i) + dfs2(i) - 1 == n) ans++;
    }
        
    cout << ans << "\n";
}

int main(){
    IOS; solve2();
    return 0;
}
