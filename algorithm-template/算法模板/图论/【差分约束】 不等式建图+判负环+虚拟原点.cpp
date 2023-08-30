/**
 * 模板题
 * https://www.luogu.com.cn/problem/P5960
 * 
 * 差分约束 推荐文章
 * https://www.luogu.com.cn/blog/wsyhb/p5960-mu-ban-ci-fen-yue-shu-suan-fa-ti-xie
 */

////////////////////////////////////////////////////////////////////////////////////////////////////


// 模板题 方法1
// 求最短路 + SPFA + 虚拟原点
// ai <= aj + k 转换为 j -> i 有条长度为 k的边 求最短路 
// 那么ai 就转化成了源点到 点i的最短路 初始化 INF

// #include <bits/stdc++.h>
// #define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// using namespace std;
// const int N = 5e3 + 10 , INF = 0x3f3f3f3f;
// typedef pair<int,int> PII;
// int n,m;
// int dist[N],cnt[N],inq[N];

// vector<PII> g[N];

// bool spfa(){
//     memset(dist,0x3f,sizeof dist);
//     for(int i=1;i<=n;i++) g[0].push_back({i,0});
//     queue<int> q; q.push(0); inq[0] = 1; dist[0] = 0; cnt[0] = 1;

//     while(q.size()){
//         int u = q.front(); q.pop();
        
//         inq[u] = 0;

//         for(auto [v,w] : g[u]){
//             if(dist[v] > dist[u] + w){
//                 dist[v] = dist[u] + w;
//                 cnt[v] = cnt[u] + 1;
//                 if(cnt[v] > n+1) return true;
//                 if(!inq[v]){
//                     q.push(v) , inq[v] = 1;
//                 }
//             }
//         } 
//     }
//     return false;
// }

// void solve(){
//     cin>>n>>m;
//     for(int i=0;i<=n;i++) g[i].clear();
//     for(int i=0;i<m;i++){
//         int u,v,w; cin>>u>>v>>w;
//         g[v].push_back({u,w});
//     }
//     if(spfa()) cout << "NO" << "\n";
//     else {
//         for(int i=1;i<=n;i++) cout << dist[i] << " \n"[i==n];
//     }
// }

// int main(){
//     IOS; solve();
//     return 0;
// }

////////////////////////////////////////////////////////////////////////////////////////////////////

// 模板题 方法2
// 求最长路+ SPFA + 虚拟原点
// ai >= aj + k 转换为 j -> i 有条长度为 k的边 求最长路
// 那么ai 就转化成了源点到 点i的最长路 初始化 -INF

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e3 + 10 , INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
int n,m;
int dist[N],cnt[N],inq[N];

vector<PII> g[N];

bool spfa(){
    memset(dist,-0x3f,sizeof dist);
    for(int i=1;i<=n;i++) g[0].push_back({i,0});
    queue<int> q; q.push(0); inq[0] = 1; dist[0] = 0; cnt[0] = 1;

    while(q.size()){
        int u = q.front(); q.pop();
        
        inq[u] = 0;

        for(auto [v,w] : g[u]){
            if(dist[v] < dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] > n+1) return true;
                if(!inq[v]){
                    q.push(v) , inq[v] = 1;
                }
            }
        } 
    }
    return false;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<=n;i++) g[i].clear();
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,-w});
    }
    if(spfa()) cout << "NO" << "\n";
    else {
        for(int i=1;i<=n;i++) cout << dist[i] << " \n"[i==n];
    }
}

int main(){
    IOS; solve();
    return 0;
}