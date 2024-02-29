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
    int n; cin>>n;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    auto check = [&](int x) -> int {
        if(a[x] > b[x]) return 0;
        if(a[x] == b[x]) return 1;
        int fl = 0, fr = 0;
        int l = x, r = x;
        for(int i=l;i>=1;i--){
            if(a[i] > b[x] || b[i] < b[x]) break;
            else if(a[i] == b[x]) {
                fl = 1; break;
            } 
        }
        for(int i=r;i<=n;i++){
            if(a[i] > b[x] || b[i] < b[x]) break;
            else if(a[i] == b[x]) {
                fr = 1; break;
            } 
        }
        return fl || fr;
    };
    for(int i=1;i<=n;i++)
        if(!check(i)){
            cout << "NO" << "\n";
            return;
        }
    cout << "YES" << "\n";
    return;
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
