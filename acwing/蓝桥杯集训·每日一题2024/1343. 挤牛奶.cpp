#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
    int l,r;
    bool operator < (const Node& o) const {
        return l != o.l ? l < o.l : r < o.r;
    }
};

void solve(){
    int n; cin>>n;
    vector<Node> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i].l>>vec[i].r;
    sort(vec.begin(), vec.end());
    vector<Node> res;
    int L = -1,R = -1;
    for(int i=0;i<n;i++){
        if(L == -1 && R == -1){
            L = vec[i].l, R = vec[i].r;
        }else{
            auto [l,r] = vec[i];
            if(l <= R) R = max(R, r);
            else {
                res.push_back({L,R});
                L = l, R = r;
            }
        }
    }
    if(L != -1 && R != -1) res.push_back({L,R});
    int ans1 = 0, ans2 = 0;
    for(int i=0;i<res.size();i++){
        ans1 = max(ans1, res[i].r - res[i].l);
        if(i > 0) ans2 = max(ans2, res[i].l - res[i-1].r);
    }
    cout << ans1 << " " << ans2 << "\n";
}

signed main(){
    solve();
    return 0;
}
