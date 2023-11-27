#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> l(n+1,0),r(n+1,0);
    string s; cin>>s; s = "?" + s;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    int ans = INF;
    function<void(int,int)> dfs = [&](int u,int sum) -> void {
        if(!l[u] && !r[u]){
            ans = min(ans,sum);
            return;
        }
        if(l[u]) dfs(l[u],sum+(s[u] != 'L'));
        if(r[u]) dfs(r[u],sum+(s[u] != 'R'));
    };
    dfs(1,0);
    cout << ans << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
