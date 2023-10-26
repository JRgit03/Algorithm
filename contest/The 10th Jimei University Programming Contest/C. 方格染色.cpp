#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define ONLINE_JUDGE  
using namespace std;
const int N = 1e5 + 10, Mod = 998244353, INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef long long ll;
int fact[N],infact[N];

int C(int a,int b){
    if(b > a) return 0;
    return fact[a] * infact[a-b] % Mod * infact[b] % Mod;
}

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % Mod;
        b >>= 1;
        a = a * a % Mod;
    }
    return res;
}

void init(){
    fact[0] = infact[0] = 1;
    for(int i=1;i<=100000;i++){
        fact[i] = fact[i-1] * i % Mod;
        infact[i] = infact[i-1] * fastpow(i,Mod-2) % Mod;
    }
}

void solve(){
    int n,k; cin>>n>>k;
    int ans = (k == 0 ? 1 : 0); 
    for(int i=1;i<=k;i++){
        ans = (ans + fastpow(2,i) * C(k-1,i-1) % Mod * C(n-k+1,i) % Mod + Mod) % Mod;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    init();
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
