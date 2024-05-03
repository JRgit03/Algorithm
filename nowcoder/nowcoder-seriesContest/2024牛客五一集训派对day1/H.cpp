#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define int long long
#define fi first
#define se second
using namespace std;

#ifdef LOCAL
#include "../../../algorithm-template/debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void solve(){
    int n = 6;
    vector<int> g[n], d(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v; u--,v--;
        d[u] += 1, d[v] += 1;
        g[u].push_back(v); g[v].push_back(u);
    }
    map<int,int> cnt; for(auto &x : d) cnt[x] += 1;
    if(cnt[4] == 1) cout << "2,2-dimethylbutane" << "\n";
    else if(cnt[3] == 2) cout << "2,3-dimethylbutane" << "\n";
    else if(cnt[2] == 4) cout << "n-hexane" << "\n";
    else {
        int suc = 0;
        for(int i=0;i<n;i++) if(d[i] == 3) {
            int sz1 = 0, sz2 = 0;
            for(auto &v : g[i]){
                debug(i, v, d[v]);
                if(d[v] == 1) sz1 += 1;
                else if(d[v] == 2) sz2 += 1;
            }
            if(sz2 == 2) suc = 1;
            debug(i, sz1, sz2);
        }
        cout << (suc ? "3-methylpentane" : "2-methylpentane") << "\n";
    }
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
