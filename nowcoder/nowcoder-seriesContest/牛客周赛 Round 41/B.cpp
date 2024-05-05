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
    int n,k; cin>>n>>k; 
    if(k == 1 || k > n) {
        cout << -1 << "\n";
        return;
    } 
    k = n - k;
    vector<int> a(n); for(auto &x : a) cin>>x; 
    vector<int> ans(n);
    for(int i=0;i<k;i++) ans[i] = a[i];
    for(int i=k;i<n-1;i++) ans[i] = a[i+1];
    ans[n - 1] = a[k];
    debug(ans); 
    for(auto &x : ans) cout << x << " "; cout << "\n";
}

signed main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--)
        solve();
    return 0;
}
