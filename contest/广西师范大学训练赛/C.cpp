#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
#define ONLINE_JUDGE  
using namespace std;
const int N = 2e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n,m; cin>>n>>m;
    vector<string> vec(n);
    vector<int> c(m+1);
    map<string,int> mp;
    for(auto &x : vec) cin>>x;
    for(int i=0;i<m;i++){
        string x; cin>>x;
        mp[x] = i+1;
    }
    for(int i=0;i<=m;i++) cin>>c[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!mp.count(vec[i])) ans += c[0];
        else ans += c[mp[vec[i]]];
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}
