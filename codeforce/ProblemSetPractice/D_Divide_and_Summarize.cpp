#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int n,q;
set<int> st; 
int a[maxn];
int s[maxn];

void dfs(int l,int r){
    if(l > r) return;
    st.insert(s[r] - s[l-1]);
    if(a[l] == a[r]) return;
    int mid = (a[l] + a[r]) >> 1;
    int k = upper_bound(a+1,a+1+n,mid) - a;
    if(k == n+1) return;
    dfs(l,k-1);dfs(k,r);
}

void solve(){
    cin>>n>>q; st.clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
    dfs(1,n);
    while(q--){
        int x; cin>>x;
        cout << (st.count(x) ? "Yes" : "No") << "\n";
    }
}

signed main(){
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
