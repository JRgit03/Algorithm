#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,q;
int x[N];
int s[N];
int ans[N];
vector<int> vec[N];

void solve(){
    cin>>n>>q;
    for(int i=1;i<=q;i++) cin>>x[i];
    set<int> st;
    for(int i=1;i<=q;i++){
        if(st.count(x[i])) st.erase(st.lower_bound(x[i]));
        else st.insert(x[i]);
        s[i] = st.size(); 
        s[i] += s[i-1]; // cout << s[i] << " "; if(i == q) cout << "\n"; 
    } 
    for(int i=1;i<=q;i++) vec[x[i]].push_back(i);
    for(int i=1;i<=q;i++){
        int l = 0, r = vec[x[i]].size() - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(vec[x[i]][mid] <= i) l = mid;
            else r = mid - 1;
        }
        if((r + 1) & 1) {
            int rr = (r + 1 < vec[x[i]].size() ? vec[x[i]][r+1] : q + 1);
            // cout << rr << " " << s[rr] << " " << s[i-1] << "\n";
            ans[x[i]] += s[rr - 1] - s[i - 1];
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}

signed main(){
    solve();
    return 0;
}
