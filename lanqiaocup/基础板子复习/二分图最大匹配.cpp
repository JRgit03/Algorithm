#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 5e2 + 10;
int n1,n2,m; // n1:集合1点数 n2集合2点数
int match[N]; // match[i] 表示 n2集合第i位与n1集合匹配的对象位置 0表示未匹配
int st[N]; // st[i] 表示 n2集合第i位是否被遍历过
vector<int> g[N];

int find(int u){ // 加入u模拟匹配,查看匹配数量会不会变多
    for(auto &v : g[u]){ // 遍历匹配对象
        if(!st[v]){
            st[v] = 1;
            if(match[v] == 0 || find(match[v])){
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

// O(nm)
void solve(){
    cin>>n1>>n2>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); // n1集合连向n2集合的边 单向边!
    }
    int res = 0;
    for(int i=1;i<=n1;i++){
        memset(st, 0, sizeof st); // 每次匹配预定情况不同,每轮都要初始化
        if(find(i)) res += 1; 
    }
    cout << res << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
