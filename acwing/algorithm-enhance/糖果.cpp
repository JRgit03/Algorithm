#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
const int N = 1e5 + 10 , INF = 0x3f3f3f3f;
typedef long long ll;
int n,m;
ll dist[N]; int inq[N],cnt[N];

vector<pair<int,int>> g[N];

// b >= a + 1  a -> b , w = 1 => 最长路 + spfa + 虚拟原点
bool spfa(){
    memset(dist,-0x3f,sizeof dist);
    for(int i=1;i<=n;i++) g[0].emplace_back(i,1); //每个人至少一个
    queue<int> q; q.push(0); inq[0] = 1; cnt[0] = 1; dist[0] = 0;

    while(q.size()){
        int u = q.front(); q.pop();
        inq[u] = 0;
        
        for(auto &[v,w] : g[u]){
            if(dist[v] < dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] > n+1) return true;
                if(!inq[v]){
                    q.push(v); inq[v] = 1;
                }
            }
        }
    }  

    return false;
}

void solve(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int op,a,b;scanf("%d %d %d",&op,&a,&b);
        if(op == 1) g[a].emplace_back(b,0) , g[b].emplace_back(a,0);
        else if(op == 2) g[a].emplace_back(b,1);
        else if(op == 3) g[b].emplace_back(a,0);
        else if(op == 4) g[b].emplace_back(a,1);
        else if(op == 5) g[a].emplace_back(b,0);
    }
    if(spfa()) printf("-1\n");
    else{
        ll ans = 0;
        for(int i=1;i<=n;i++) ans += dist[i];
        printf("%lld\n",ans);
    }
}

int main(){
    solve(); return 0;
}
