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
    string str; cin>>str;
    string t = "HEBUT";
    int ans = 0;
    auto calc = [&](string s){
        int k = 0;
        while((k = str.find(s,k)) != -1) {
            ans += 1;
            k += 1;
        }
    };
    for(int i=1;i<=5;i++) calc(t.substr(0,i));
    cout << ans << "\n";
} 

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
