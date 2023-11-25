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
    vector<int> vec(3); for(auto &x : vec) cin>>x;
    sort(vec.begin(),vec.end());
    if(vec[0] + vec[1] <= vec[2]){
        cout << -1 << "\n";
        return;
    } 
    int s = accumulate(vec.begin(),vec.end(),0) / 2;
    cout << s * (s - vec[0]) * (s - vec[1]) * (s - vec[2]) << "\n";
}

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
