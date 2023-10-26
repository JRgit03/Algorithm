#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl "\n"
#define dbug(x) cout << 'x = ' << x << endl
#define int long long
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n,m; cin>>n>>m;
    int mul = n * m;
    cout << ((mul % 6 == 0 && n > 1 && m > 1) ? "Yes" : "No") << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
