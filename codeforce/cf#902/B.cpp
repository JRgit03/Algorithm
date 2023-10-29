#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
#define ONLINE_JUDGE  
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n,m; cin>>n>>m;
    string s,t; cin>>s>>t;
    char pre = t.front() , suf = t.back();
    auto check = [&](){
        bool f = true;
        for(int i=1;i<m;i++)
            f &= (t[i] != t[i-1]);
        return f;
    };
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]){
            if(s[i-1] != pre && s[i] != suf && check()) continue;
            else {
                cout << "No" << "\n";
                return;
            }
        }
    }
    cout << "Yes" << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
