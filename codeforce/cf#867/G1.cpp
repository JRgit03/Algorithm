#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxV = 1e6;

void solve(){
    int n; cin>>n;
    set<int> st;map<int,int> cnt;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        st.insert(x); cnt[x]++;
    }

    int res = 0;
    for(auto x : st){
        if(cnt[x]>=3) res += cnt[x] * (cnt[x] - 1) * (cnt[x] - 2);
        for(int y=2;y<=3000 && x*y*y <= maxV;y++){
            if(cnt.count(x*y) && cnt.count(x*y*y))
                res += cnt[x] * cnt[x*y] * cnt[x*y*y]; 
        }
    }

    cout << res << "\n";
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
