#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int dist[N],maxl,sum;
int p[N];

int dfs(int u){ //从下往上找
    if(p[u]==-1 || dist[u]) return dist[u];
    else sum++; //没访问过当前点
    dist[u] = dfs(p[u]) + 1;
    return dist[u];
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i];
    while(m--){
        int x;cin>>x;
        maxl = max(maxl , dfs(x));
        printf("%d\n",2*sum-maxl);
    }
    return 0;
}
