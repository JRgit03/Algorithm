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
    int n,m; cin>>n>>m;
    vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
    string s; cin>>s; 
    vector<int> ans, vec;
    int l = 0, r = n - 1;
    for(auto c : s) {
        if(c == 'L') vec.push_back(a[l++]);
        else vec.push_back(a[r--]);
    }
    reverse(vec.begin(), vec.end());
    int v = 1;
    for(auto x : vec) {
        v = v * x % m;
        ans.push_back(v);
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " "; cout << "\n";
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
