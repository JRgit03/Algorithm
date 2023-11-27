#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q; cin>>n>>q;
    vector<int> a(n+1);
    set<int> ones; int s = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i]; s += a[i];
        if(a[i] == 1){
            ones.insert(i);
        }
    }
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int t; cin>>t;
            if(t > s) {
                cout << "NO" << "\n";
            }else{
                if(!ones.size()) cout << ((t % 2 == 0) ? "YES" : "NO") << "\n";
                else{
                    int l = *ones.begin() - 1, r = n - *ones.rbegin();
                    int sum = s - (l + r) * 2 + max(l,r) * 2;
                    if(t <= sum || (sum % 2 == t % 2 && (t - sum) <= min(l,r) * 2)) cout << "YES" << "\n";
                    else cout << "NO" << "\n";
                }
            }
        }else{
            int i,v; cin>>i>>v; s = s - a[i] + v;
            if(a[i] == 1) ones.erase(i);
            a[i] = v; if(a[i] == 1) ones.insert(i);
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
