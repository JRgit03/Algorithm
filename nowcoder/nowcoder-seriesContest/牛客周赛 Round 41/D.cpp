#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define int long long
using namespace std;

#ifdef LOCAL
#include "../../../algorithm-template/debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void solve(){
    int n,q; cin>>n>>q;
    string s; cin>>s;
    vector<int> r(n+1),e(n+1),d(n+1);
    for(int i=0;i<n;i++){
        if(s[i] == 'r') r[i+1] += 1;
        if(s[i] == 'e') e[i+1] += 1;
        if(s[i] == 'd') d[i+1] += 1;
        r[i+1] += r[i], e[i+1] += e[i], d[i+1] += d[i];
    }    
    auto query = [&](int x,int y,char c){
        if(c == 'r') return r[y] - r[x-1];
        if(c == 'e') return e[y] - e[x-1];
        return d[y] - d[x-1];
    };
    while(q--){
        int l,r; cin>>l>>r;
        int len = r - l + 1;
        vector<int> sz(3, len / 3);
        for(int i=0;i<len%3;i++) sz[i] += 1;
        int ans = len;
        sort(sz.begin(), sz.end());  debug(sz, len);
        do{
            int res = 0,st = l, ed = -1;
            for(int k=0;k<3;k++){
                ed = st + sz[k] - 1;
                debug(st, ed);
                debug(query(st,ed,"red"[k]));
                res += sz[k] - query(st,ed,"red"[k]);
                st = ed + 1;
            }
            ans = min(ans, res);
        }while(next_permutation(sz.begin(), sz.end()));
        if(len < 3) ans = 0;
        cout << ans << "\n";
    }
}

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
