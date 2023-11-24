#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> k[22];
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        k[a].push_back(b);
    }    
    for(int i=1;i<=20;i++) sort(k[i].begin(),k[i].end());
    int q; cin>>q;
    while(q--){
        int qk,qm,x; cin>>qk>>qm>>x;
        int l = 0, r = k[qk].size() - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(k[qk][mid] <= qm) l = mid;
            else r = mid - 1;
        }
        cout << r << "\n";
        int cnt = k[qk].size(); // 有多少人伤害 > qm
        if(k[qk][r] <= qm) cnt = cnt - (r + 1);
        for(int i=qk+1;i<=20;i++) cnt += k[i].size();
        cnt++;
        cout << (cnt >= x ? "YES" : "NO") << "\n";
    }
}  

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
