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
const int maxn = 2e5 + 10;

int c[maxn];
int b[maxn];

void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) b[i] = c[i] - c[i-1]; 
    b[1] -= 1;
    int ans = 0;
    for(int i=1;i<=n;i++)
        if(b[i] > 0)
            ans += b[i];
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
