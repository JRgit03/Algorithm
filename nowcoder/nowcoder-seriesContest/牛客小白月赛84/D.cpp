#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
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
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

struct Node{
    int l,r;
    
    bool operator < (const Node &o) const {
        return l < o.l;
    }
};


void solve(){
    int n,q; cin>>n>>q;
    string s; cin>>s; s = "?" + s;
    set<Node> st;
    for(int i=1;i<=n;i++){
        if(s[i] == '0') continue;
        int j = i;
        while(j<=n && s[j] == '1') j++;
        st.insert({i,j-1}); i = j - 1;
    }
    while(q--){
        int l,r; cin>>l>>r;
        if(s[l] == s[r]) cout << st.size() << "\n";
        else{
            int ans = st.size();
            if(s[l] == '1' && s[r] == '0'){
                if(r+1<=n && s[r+1] == '1') ans--;
                if(l-1>=1 && s[l-1] == '1') ans++; 
            }else{ 
               if(r+1<=n && s[r+1] == '1') ans++;
               if(l-1>=1 && s[l-1] == '1') ans--; 
            }
            cout << ans << "\n";
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
