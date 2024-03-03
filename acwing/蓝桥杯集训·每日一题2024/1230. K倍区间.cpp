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

void init(){
    
}

int n,k;
int a[N];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s = 0, ans = 0;
    map<int,int> mp; // mp[x] = c 前缀和对k取模值为x出现的次数
    mp[0] = 1;
    for(int i=1;i<=n;i++){
        s = (s + a[i]) % k;
        ans += mp[s];
        mp[s] += 1;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    init();
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
