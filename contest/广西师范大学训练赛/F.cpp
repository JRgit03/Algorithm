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
int n;
int a[N];

void solve(){
    int s = 0; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i], s ^= a[i];
    for(int i=1;i<=n;i++) cout << (s ^ a[i]) << " ";
}

signed main(){
    IOS;
    // int t;cin>>t;
    // while(t--)
        solve();
    return 0;
}
