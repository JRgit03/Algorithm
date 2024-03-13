#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
using namespace std;

void solve(){
    int n,d; cin>>n>>d;
    int cur = 0;
    vector<int> s(n); for(auto &x : s) cin>>x;
    vector<int> p(n); for(auto &x : p) cin>>x;
    cur = s[d - 1] + p[0];
    int l = 1, r = n - 1;
    vector<int> v; for(int i=0;i<n;i++) if(i+1 != d) v.push_back(s[i]);
    vector<int> rk;
    for(auto &x : v){
        if(x >= cur){
            rk.push_back(x + p[l++]);
        }else if(x <= cur){
            if(x + p[r] < cur){
                rk.push_back(x + p[r--]);
            }else{
                rk.push_back(x + p[r--]);
            }
        }
    }
    sort(rk.begin(), rk.end(), greater<int>());
    // debugsq(rk);
    vector<int> b(n-1);
    b[0] = 1;
    for(int i=1;i<n-1;i++){
        if(rk[i] == rk[i-1]) b[i] = b[i-1];
        else  b[i] = b[i-1] + 1;
    }
    // debugsq(b);
    l = 0, r = n - 2;
    while(l < r){
        int mid = l + r >> 1;
        if(rk[mid] <= cur) r = mid;
        else l = mid + 1;
    }
    int ans = 0;
    if(cur >= rk[r]) ans = b[r];
    else ans = b[r] + 1;
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
