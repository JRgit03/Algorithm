#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void solve(){
    int n,m,k; cin>>n>>m>>k;
    map<int,int> mp,mp2;
    vector<int> a(n); for(auto &x : a) cin>>x;
    for(int i=0;i<m;i++){
        int x; cin>>x;
        mp[x] += 1;
    }
    int t = 0, ans = 0;
    for(int r=0,l=0;r<n;r++){
        while(l <= r && r - l + 1 > m) {
            if(mp2[a[l]] <= mp[a[l]]) t -= 1;
            mp2[a[l]] -= 1;
            l += 1;
        }
        mp2[a[r]] += 1;
        if(mp2[a[r]] <= mp[a[r]]) t += 1;
        if(r+1 >= m && t >= k) ans += 1; 
    }
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
