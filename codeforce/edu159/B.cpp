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
    int n,p,l,t; cin>>n>>p>>l>>t;
    int week = (n + 7 - 1) / 7;
    int s = week / 2 * (2 * t + l), ans = week / 2;
    if(s >= p){
        ans -= (s - p) / (2 * t + l);
    }else{
        if(week % 2 != 0){
            s += t + l; ans++;
        }
        if(s < p) ans += (p - s + l - 1) / l;
    }
    cout << n - ans << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
