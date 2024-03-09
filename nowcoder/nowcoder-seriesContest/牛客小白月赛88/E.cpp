#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
// #define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int ans[N];

void solve(){
    int n,m; cin>>n>>m;
    set<int> st;
    vector<int> a(n); for(int i=0;i<n;i++){
        cin>>a[i]; st.insert(a[i]);
    }
    map<int,vector<int>> mp;
    for(auto x : st) mp[x] = {x};
    while(m--){
        int a,b; cin>>a>>b;
        if(a == b) continue;
        int sza = mp[a].size(), szb = mp[b].size();
        if(sza > szb) swap(mp[a], mp[b]);
        for(auto x : mp[a]){
            mp[b].push_back(x);
        }
        mp[a].clear();
    }
    for(auto &[v1, vec] : mp)
        for(auto &v2 : vec)
            ans[v2] = v1;
    for(auto &x : a) cout << ans[x] << " "; cout << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
