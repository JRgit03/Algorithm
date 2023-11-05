/**
 * 
 * 每个点最多被分治logn次 时间复杂度为nlogn 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4 + 10,maxk=1e7+10,maxq=110;
// rt重心 sum以重心为根的树的大小
int n,m,rt,sum;
// siz记录子树大小 dis[i]为rt与i之间距离
// f[u] 表示除去点u的最大子树大小
int tmp[maxn],cnt;
int siz[maxn],dis[maxn],f[maxn];
int q[maxq];
// tmp记录算出的距离
// judge[i]记录在之前子树中距离i是否存在 ans记录第q个询问是否存在 vis记录被删除的节点
bool judge[maxk],ans[maxq],vis[maxn];

vector<pair<int,int>> g[maxn];

// 找重心
void getrt(int u,int fa){
    siz[u] = 1,  f[u] = 0;
    for(auto [v,w] : g[u]){
        if(v == fa || vis[v]) continue; // 删除的点不考虑
        getrt(v,u);
        siz[u] += siz[v];
        if(siz[v] > f[u]) f[u] = siz[v]; //考虑u的直接儿子
    }
    f[u] = max(f[u],sum-siz[u]); //考虑u的祖先节点
    if(f[u] < f[rt]) rt = u; //更新重心 最大子树大小最小
}

// 计算各节点与根节点之间的距离并全部记录在tmp
void getdis(int u,int fa){
    tmp[cnt++] = dis[u];
    for(auto [v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        dis[v] = dis[u] + w;
        getdis(v,u);
    } 
}

// 不同题目的calc()函数 不同！
// 处理经过根节点的路径
// ！注意judge数组要存在之前子树例存在的路径长度，排除折返路径的可能
void calc(int u){
    queue<int> que;
    for(auto [v,w] : g[u]){
        if(vis[v]) continue;
        cnt = 0; // 计算器置零
        dis[v] = w;
        getdis(v,u); //预处理距离
        for(int j=0;j<cnt;j++){ //遍历所有距离
            for(int k=0;k<m;k++){ //遍历所有询问 
                if(q[k] >= tmp[j]){ //如果询问大于单挑路径 则可能存在
                    ans[k] |= judge[q[k] - tmp[j]]; //判断是否能用两条路径拼接
                }
            }
        }
        for(int j=0;j<cnt;j++){ //处理完当前子树 更新judge把存在的单挑路径长度标记true 供后面子树使用
            if(tmp[j] > 10000000) continue; // 路径长度可能大于1e7 特判
            que.push(tmp[j]);
            judge[tmp[j]] = true;
        }
    }t
    while(que.size()){ // 清空judge数组 不能使用memse 使用memset时间复杂度上升 为下一次分治使用
        judge[que.front()] = false; 
        que.pop();
    }
}

// 分治
void divide(int u){
    vis[u] = judge[0] = true; //删除根节点u judge[0]显然符合
    calc(u); //计算经过根节点的路径
    for(auto [v,w] : g[u]){ //分治剩余部分
        if(vis[v]) continue;
        f[rt=0]=sum=siz[v]; //把重心置为0 并把f[0]置为最大值 
        getrt(v,0);
        getrt(rt,0); //与主函数相同 第二次更新siz大小
        divide(rt);  
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w}); g[v].push_back({u,w});
    }
    for(int i=0;i<m;i++) cin>>q[i];
    f[0]=sum=n; // f[0]置为最大值（开始 rt=0）
    getrt(1,0); //找重心 !第一次找完重心后 siz数组存在的是以1为根节点时的子树大小 需要以找出的重心为根重新算
    getrt(rt,0); //重新计算以rt为根的siz大小
    divide(rt); //找好重心开始分治
    for(int i=0;i<m;i++) cout << (ans[i] ? "AYE" : "NAY") << "\n";
    return 0;
}
