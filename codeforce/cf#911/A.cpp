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
    map<int,int> mp;
    bool flag = false;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == '#') continue;
        int j = i;
        while(j<n && s[j] == '.') j++;
        int len = j - i;
        mp[len] += 1;
        if(len > 2) flag = true;
        i = j - 1;
    }
    int ans = 0;
    if(flag) ans = 2;
    else{
        for(auto [a,b] : mp) ans += a * b;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
