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

void solve(){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n-1;i++) cout << i << " " << i+1 << "\n";
    int now = n - 1; // 节点n连接在now点上
    while(q--){
        int t; cin>>t;
        if(t == now) cout << -1 << " " << -1 << " " << -1 << "\n";
        else {
            cout << n << " " << now << " " << t << "\n";
            now = t;
        }
    }
}

signed main(){
    IOS;
    init();
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
