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
    string s; cin>>s;
    int maxx = -1;
    vector<int> cnt(26); for(auto c : s){
        maxx = max(maxx,++cnt[c-'a']);
    }
    int re = n - maxx;
    if(maxx <= re){
        cout << (n&1) << "\n";
    }else{
        cout << maxx - re << "\n";
    }
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
