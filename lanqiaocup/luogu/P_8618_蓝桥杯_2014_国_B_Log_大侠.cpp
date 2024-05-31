#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10, up = 1e6;
int n,m;
int a[N];

int f(int x){
    return (int)log2(x) + 1;
}

// AC 30/100
void solve1(){
    int ans = 0;
    for(int i=1;i<=n;i++) ans += a[i];
    while(m--){
        int l, r; cin>>l>>r;
        for(int i=l;i<=r;i++){
            int cur = f(a[i]);
            ans = ans - a[i] + cur;
            a[i] = cur;
        } 
        cout << ans << "\n";
    }
}

void solve2(){
    int ans = 0;
    set<int> st;
    for(int i=1;i<=n;i++) {
        ans += a[i];
        if(a[i] > 2) st.insert(i);
    }
    while(m--){
        int l,r; cin>>l>>r;
        vector<int> del;
        for(auto it = st.lower_bound(l); it != st.upper_bound(r); it++){
            int idx = *it;
            int cur = f(a[idx]);
            ans = ans - a[idx] + cur;
            a[idx] = cur;
            if(a[idx] <= 2) del.push_back(idx);
        }
        for(auto &x : del) st.erase(st.lower_bound(x));
        cout << ans << "\n";
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n * m <= up) solve1();
    else solve2();   
}

signed main(){
    IOS;
    solve();
    return 0;
}
