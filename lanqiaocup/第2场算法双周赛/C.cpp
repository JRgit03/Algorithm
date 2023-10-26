#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    vector<int> dif(n-1);
    for(int i=0;i<n-1;i++) dif[i] = vec[i+1] - vec[i];
    sort(dif.begin(),dif.end());
    int ans = 0;
    for(int i=0;i<(n-1)-(k-1);i++) ans += dif[i];
    cout << ans << "\n";
}

signed main(){
    IOS;
    // int t;cin>>t;
    // for(int i=0;i<t;i++)
        solve();
    return 0;
}
