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
    vector<int> p(n+1),sz(n+1,1); iota(p.begin(),p.end(),0);
    function<int(int)> find = [&](int x) -> int{
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    };
    for(int i=1;i<=n;i++){
        int to; cin>>to;
        int pa = find(i), pb = find(to);
        if(pa != pb){
            p[pa] = pb;
            sz[pb] += sz[pa];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) 
        if(find(i) == i)
            ans = max(ans, sz[find(i)]);
    cout << ans << "\n";
} 

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
