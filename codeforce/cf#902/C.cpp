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
    int n; cin>>n;
    string s; cin>>s;
    vector<int> cnt(2);
    for(auto c : s) cnt[c - '0']++;
    if(n & 1 || cnt[0] != cnt[1]){
        cout << -1 << "\n";
        return;
    }
    vector<int> ans;
    int op = 0; 
    for(int i=0;i<n && op<=300;i++){
        if(s[i] == s[n-i-1]){
            //cout << i << " " << n-i-1 << " " << s[i] << " " << s[n-i-1] << "\n";
            if(s[i] == '0'){
                ans.push_back(n-i);
                s = s.substr(0,n-i) + "01" + s.substr(n-i); 
            }else{
                ans.push_back(i);
                s = s.substr(0,i) + "01" + s.substr(i);
            }
            n += 2, op++;
        }
    }
    if(op > 300){
        cout << -1 << "\n";
        return;
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " "; cout << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
