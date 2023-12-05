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
    vector<int> cnt(2);
    for(auto c : s) cnt[c-'0'] += 1;
    if(cnt[0] > cnt[1]) {
        cout << "YES" << "\n";
        return;
    }
    bool suc = false; // 00 / 10
    for(int i=1;i<n;i++)
        if(s[i] - '0' + s[i-1] - '0' == 1 || s[i] - '0' + s[i-1] - '0' == 0)
            suc = true;
    cout << (suc ? "YES" : "NO") << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
