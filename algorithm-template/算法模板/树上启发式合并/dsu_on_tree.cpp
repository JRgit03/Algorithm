/**
 * 处理树上离线问题 O(nlogn)
 * 对于每个子树，输出子树中出现次数最多的节点编号之和
 * https://codeforces.com/contest/600/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;

vector<int> g[maxn];

int siz[maxn]; // siz[x] 子树x大小
int son[maxn]; // son[x] 子树x的重儿子

void dfs_son(int u,int f){
    siz[u] = 1;
    int maxsize = -1;
    for(auto v : g[u]){
        if(v == f) continue;
        dfs_son(v,u);
        siz[u] += siz[v];
        if(siz[v] > maxsize){
            son[u] = v;
            maxsize = siz[v];
        } 
    }
    //printf("son[%d] : %d\n",u,son[u]);
}

int col[maxn],cnt[maxn]; // col存在节点颜色 cnt存在颜色在'当前'子树的数量
int flag; // flag标记重儿子
ll sum,maxc; // sum统计当前子树的答案 maxc用于更新最大值
ll ans[maxn];

// 暴力统计节点u及其所有轻儿子的贡献
void count(int u,int f,int val){
    cnt[col[u]] += val;
    if(cnt[col[u]] > maxc){
        maxc = cnt[col[u]];
        sum = col[u];
    }else if(cnt[col[u]] == maxc){
        sum += col[u];
    }
    // 排除'被标记的重儿子'，统计轻儿子子树对答案的贡献
    for(auto v : g[u]){
        if(v == f || v == flag) continue;
        count(v,u,val);
    }
}

// DSU On Tree 板子
void dfs(int u,int f,bool keep){ // keep是否保留贡献
    // 第一步：计算轻儿子及其子树的贡献 并 删除
    for(auto v : g[u]){ 
        if(v == f || v == son[u]) continue;
        dfs(v,u,false);
    }
    // 第二步：计算重儿子及其子树的贡献 并 保留
    if(son[u]) {
        dfs(son[u],u,true);
        flag = son[u]; //标记重儿子
    }
    // 第三步：暴力统计u及其所有轻儿子的贡献合并到刚计算出的重儿子
    count(u,f,1);
    // 更新答案以及清除标记
    flag = 0;
    ans[u] = sum;
    // 处理需要删除的贡献 清除标记
    if(!keep){
        count(u,f,-1);
        sum=maxc=0;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>col[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);   
    }
    dfs_son(1,0);
    dfs(1,0,false);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    return 0;
}
