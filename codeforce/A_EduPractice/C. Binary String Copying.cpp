#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
// #define int long long
using namespace std;
const int N = 2e5 + 10 , P = 13331;
int n,m;
string str;
typedef unsigned long long ULL;
ULL h[N],p[N];
ULL h0[N];
ULL h1[N];

int s0[N],s1[N];

ULL gethash(int l,int r, ULL h[]){
    return h[r] - h[l-1] * p[r-l+1];
}

void init(){
    str = "?" + str;
    for(int i=0;i<=n;i++) h[i] = h0[i] = h1[i] = p[i] = s0[i] = s1[i] = 0;
    p[0] = 1;
    for(int i=1;i<=n;i++){
        h[i] = h[i-1] * P + str[i];
        h0[i] = h0[i-1] * P + '0';
        h1[i] = h1[i-1] * P + '1';
        p[i] = p[i-1] * P;
        if(str[i] == '0') s0[i] = 1;
        if(str[i] == '1') s1[i] = 1;
        s0[i] += s0[i-1];
        s1[i] += s1[i-1];
    }
}

ULL calc(int l,int r){
    int sz0 = s0[r] - s0[l-1], sz1 = s1[r] - s1[l-1];
    // debug(sz0); debug(sz1); cerr << "\n";
    // cerr << l << " " << l + sz0 - 1 << "\n"; debug(gethash(l, l + sz0 - 1, h0)); 
    // cerr << l + sz0 << " " << r << "\n"; debug(gethash(l + sz0, r, h1));
    return gethash(l, l + sz0 - 1, h0) * p[n - (l + sz0 - 1)] + gethash(l + sz0, r, h1) * p[n - (r)];
}

void solve(){
    cin>>n>>m;
    cin>>str;
    init();
    map<ULL, int> mp;
    while(m--){
        int l,r; cin>>l>>r;
        // cerr << 1 << " " << l-1 << "\n";  debug(gethash(1, l-1, h)); 
        // cerr << r+1 << " " << n << "\n"; debug(gethash(r+1, n, h)); 
        ULL x = gethash(1, l-1, h) * p[n - (l - 1)] + gethash(r+1, n, h) + calc(l,r); 
        // debug(x); cerr << "\n";
        // cout << l << " " << r << " " << x << "\n";
        mp[x] += 1;
    }
    cout << mp.size() << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
