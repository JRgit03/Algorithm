/**
 *  静态点分治
 *  https://codeforces.com/contest/161/submission/231475841
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10, maxk = 5e2 + 10;
int n,k,ans;
vector<int> g[maxn];

int sum; //以rt为根的子树大小
int rt; //rt 重心：最大子树的节点数最小
int f[maxn],siz[maxn]; // f[u] 以u为根除去u的最大子树大小(包括祖先) siz[u] 以u为根的子树大小

bool vis[maxn]; // vis[i] 当前节点是否被删除

int cnt,tmp[maxn];
int dis[maxn],mp[maxn]; // dis[i] i到rt的距离 mp[i]距离为i的路径出现次数

void getrt(int u,int fa){
    siz[u] = 1, f[u] = 0;
    for(auto v : g[u]){
        if(v == fa || vis[v]) continue;
        getrt(v,u);
        siz[u] += siz[v];
        if(siz[v] > f[u]) f[u] = siz[v];
    }
    f[u] = max(f[u],sum-siz[u]);
    if(f[u] < f[rt]) rt = u;
} 

void getdis(int u,int fa){
    tmp[cnt++] = u; //记录点
    for(auto v : g[u]){
        if(v == fa || vis[v]) continue;
        dis[v] = dis[u] + 1;
        getdis(v,u);
    }
}

// 处理经过点u的路径
// 需要特殊处理处于同一子树的情况 即不能有往返路线
void calc(int u){ 
    queue<int> que;
    for(auto v : g[u]){
        if(vis[v]) continue;
        cnt = 0; //计数器置零
        dis[v] = 1;
        getdis(v,u);
        for(int j=0;j<cnt;j++) //处理以v为根的子树
            if(k >= dis[tmp[j]])
                ans += mp[k-dis[tmp[j]]];
        for(int j=0;j<cnt;j++){ //处理完当前子树 存入到mp
            que.push(tmp[j]);
            mp[dis[tmp[j]]]++;
        }
    }
    while(que.size()){ //清空mp为下一次分治使用
        mp[dis[que.front()]]--;
        que.pop();
    }
}

void divide(int u,int fa){
    vis[u] = true; mp[0] = 1;
    calc(u);
    for(auto v : g[u]){
        if(v == fa || vis[v]) continue;
        rt = 0; f[0] = sum = siz[v]; // 重新分治 siz[v] 是以u为根时 v的子树大小
        getrt(v,0);
        getrt(rt,0);
        divide(rt,0);
    }
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    f[0] = sum = n; // rt初始为0 f[0] 要一个大值
    getrt(1,0); //得到树的重心
    getrt(rt,0); //重新计算以rt为根的siz子树大小
    divide(rt,0); //点分治
    cout << ans << "\n";
    return 0;
}
