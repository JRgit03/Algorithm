#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10 , INF = 0x3f3f3f3f;
int n,m,op;
int a,b,c;
vector<pair<int,int>> g[N];

int dist[N],inq[N],Neg[N];
int spfa(int s){
    memset(Neg,0,sizeof Neg); Neg[s] = 1;
    dist[s] = 0; for(int i=1;i<=n;i++) dist[i] = INF , inq[i] = 0;
    queue<int> q; q.push(s); inq[s] = 1;

    while(q.size()){
        int u = q.front(); q.pop();
        
        inq[u] = 0;
        
        for(auto [v,w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(++Neg[v] > n + 1) return 1;
                if(!inq[v]){
                    inq[v] = 1; q.push(v);
                }
            }
        }
    }
    return 0;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) g[0].push_back({i,0});
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&op,&a,&b);
        if(op == 1 || op == 2){
            scanf("%d",&c);
            if(op == 1) g[a].push_back({b,-c});
            else g[b].push_back({a,c});
        }else{
            g[b].push_back({a,0}) , g[a].push_back({b,0});
        }
    }
    if(spfa(0)) printf("No\n");
    else printf("Yes\n");
}

int main(){
    solve(); return 0;
}
