#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 3e3 + 10 , INF = 0x3f3f3f3f;
int n,edgs,m; 
int a[N];
int depth[N];

int v[N],w[N];
int f[N][N];

vector<int> h[N];

void bfs(){
    memset(depth,0x3f,sizeof depth);
    queue<int> q;
    depth[1] = 0;
    q.push(1);

    while(q.size()){
        int u = q.front(); q.pop();
        
        for(auto v : h[u]){
            if(depth[v] > depth[u] + 1){
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

}

int main(){
    IOS;
    cin>>n>>edgs>>m;
    for(int i=2;i<=n;i++) cin>>a[i];
    while(edgs--){
        int u,v;cin>>u>>v;
        h[u].push_back(v) , h[v].push_back(u);
    }
    bfs();
    //for(int i=1;i<=n;i++) cout << depth[i] << " \n"[i==n];
    for(int i=1;i<=n;i++) v[i] = depth[i]*2 , w[i] = a[i];

    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++){
            f[i][j] = f[i-1][j];
            if(j>=v[i]) f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    for(int i=1;i<=m;i++) cout << f[n][i] << " \n"[i==m];
    return 0;
}
