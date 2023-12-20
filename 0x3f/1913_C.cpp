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
    vector<int> cnt(31);
    int m; cin>>m;
    while(m--){
        int op,x,w; cin>>op;
        if(op == 1) {
            cin>>x; 
            cnt[x] += 1; 
        }else{
            cin>>w;
            vector<int> cur(cnt); //debugsq(cur);
            bool suc = true;
            for(int i=0;i<=29;i++){
                if((w >> i) & 1){
                    if(cur[i] > 0){
                        cur[i] -= 1;
                    }else suc = false;
                }
                cur[i+1] += cur[i] / 2;
            }
            cout << (suc ? "YES" : "NO") << "\n";
        }
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
