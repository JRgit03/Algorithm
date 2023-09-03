/**
 * 【模板】拓扑排序 / 家谱树
 * https://www.luogu.com.cn/problem/B3644
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e2 + 10;
int n;
int d[N],q[N];
vector<int> g[N];

bool top_sort(){
    int hh = 0 , tt = -1;
    for(int i=1;i<=n;i++)
        if(!d[i]){
            q[++tt] = i;
            cout << i << " ";
        }
    while(hh <= tt){
        int u = q[hh++];
        for(auto &v : g[u]){
            if(--d[v] == 0){
                q[++tt] = v;
                cout << v << " ";
            }
        }
    }
    return tt == n-1;
}

void solve(){
    cin>>n;
    for(int u=1;u<=n;u++){
        int v;while(cin>>v){
            if(!v) break;
            g[u].push_back(v); ++d[v];
        }
    }
    top_sort();
}

int main(){
    IOS; solve();
    return 0;
}
