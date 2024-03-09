#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n,m;
int a[N];
int b[N];
int l[N],r[N];

vector<int> all;
int getPos(int x){return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;}

void solve(){
    cin>>n;
    a[0] = 0; a[n+1] = 1e9 + 1;
    all.push_back(a[0]);
    all.push_back(a[n+1]);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        all.push_back(a[i]);
    }
    cin>>m;
    vector<array<int,2>> qs;
    while(m--){
        int op,x,y; cin>>op;
        if(op == 1){
            cin>>x>>y;
            all.push_back(x); all.push_back(y);
            qs.push_back({x,y});
        }else{
            cin>>x;
            all.push_back(x);
            qs.push_back({x,-1});
        }
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()), all.end());
    for(int i=0;i<=n+1;i++) b[i] = getPos(a[i]);
    for(int i=1;i<=n+1;i++){
        r[b[i-1]] = b[i];
        l[b[i]] = b[i-1];
    }
    for(auto &v : qs){
        int x = v[0], y = v[1];
        if(y == -1){
            x = getPos(x);
            r[l[x]] = r[x];
            l[r[x]] = l[x];
        }else{
            x = getPos(x); y = getPos(y);
            r[y] = r[x];
            l[r[x]] = y;
            r[x] = y;
            l[y] = x;
        }
    }
    vector<int> ans;
    int k = r[1];
    while(k != all.size()){
        ans.push_back(all[k - 1]);
        k = r[k];
    }
    for(auto &x : ans) cout << x << " ";
}

signed main(){
    solve();
    return 0;
}
