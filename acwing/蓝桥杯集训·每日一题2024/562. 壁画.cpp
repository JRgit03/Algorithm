#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t; cin>>t;
    for(int T=1;T<=t;T++){
        int n; cin>>n;
        string s; cin>>s; s = " " + s;
        vector<int> a(n+1); for(int i=1;i<=n;i++) {
            a[i] += a[i-1] + s[i] - '0';
        }
        int ans = 0;
        int sz = (n + 2 - 1) / 2;
        for(int l=1;l<=n && l+sz-1<=n;l++){
            int r = l + sz - 1; 
            ans = max(ans, a[r] - a[l-1]);
        }
        printf("Case #%lld: %lld\n",T, ans);
    }
    return 0;
}
