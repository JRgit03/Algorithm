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
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int l,r; cin>>l>>r;
    vector<int> cnt(10);
    for(int i=l;i<=min(l+10-1,r);i++){
        int x = i;
        while(x) cnt[x%10] += 1, x /= 10;
    }    
    bool suc = true;
    for(int i=0;i<10;i++) if(!cnt[i]) suc = false;
    cout << (suc ? "Yes" : "No") << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
