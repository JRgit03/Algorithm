#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    multiset<int> st;
    vector<array<int,2>> seg(n);
    for(int i=0;i<n;i++){
        cin>>seg[i][0]>>seg[i][1];
    }
    sort(seg.begin(), seg.end(), [&](auto &p, auto &q){
        return p[1] != q[1] ? p[1] < q[1] : p[0] > q[0];
    });
    int ans = 0;
    for(int i=0;i<n;i++){
        if(st.size() == 0){
            st.insert(seg[i][1]);
            ans += 1;
        }else{ 
            auto it = st.upper_bound(seg[i][0]);
            if(it == st.begin()){
                if(st.size() + 1 <= k){
                    st.insert(seg[i][1]);
                    ans += 1;
                }
            }else{
                it--;
                st.erase(it);
                st.insert(seg[i][1]);
                ans += 1;
            }
        }
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
