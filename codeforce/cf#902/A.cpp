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
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x] += 1;
    } 
    if(mp.size() == 1){
        cout << "Yes" << "\n";
        return;
    } 
    if(mp.size() == 2){
        vector<int> v;
        for(auto [_,sz] : mp)
            v.push_back(sz);
        sort(v.begin(),v.end());
        cout << (v[1] - v[0] <= 1 ? "Yes" : "No") << "\n";
        return; 
    } 
    cout << "No" << "\n";
    return;
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
