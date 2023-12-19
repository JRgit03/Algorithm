#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define debug_(x) cerr << #x << " = " << (x) << ' '
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

int n,k; 
int a[N];

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int suf = 0,ans = 0;
    for(int i=n;i>=1;i--){
        ans = (ans + fastpow(a[i],k+1)) % mod;
        ans = (ans + a[i] * suf % mod) % mod;
        suf = (suf * 2 % mod + fastpow(a[i],k) % mod) % mod;
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}
