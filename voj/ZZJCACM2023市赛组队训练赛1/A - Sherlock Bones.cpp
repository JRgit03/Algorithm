#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    string s; cin>>s; s = "?" + s;
    int cnt = 0; for(auto &c : s) cnt += (c == '1');
    vector<int> L(cnt+1),R(cnt+1);
    int cur = 1 , sz = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == '1'){
            L[cur] = sz;
            R[cur-1] = sz;
            cur++; sz=0;
        }else{
            int j = i;
            while(j<=n && s[j] == '0') sz++, j++;
            i = j - 1;
        }
    }
    cur--; if(sz) R[cur] = sz;
    int ans = 0; n = cur;
    for(int i=1;i<=n;i++) ans += L[i] * R[i];
    for(int i=1;i<=n;i++) L[i]++, R[i]++;
    int r1=0,r2=0;
    for(int i=3;i<=n;i++){
        if(i&1) r1 += R[i];
        else r2 += R[i];
    } 
    for(int i=1;i<=n;i++){
        if(i&1) ans += L[i] * r1 , r1 -= i+2 <= n ? R[i+2] : 0;
        else ans += L[i] * r2, r2 -= i+2 <= n ? R[i+2] : 0;
    }
    cout << ans << "\n";
} 

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
