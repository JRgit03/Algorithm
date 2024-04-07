#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    int s = 0, t = 0;
    vector<int> a(n); for(auto &x : a) {
        cin>>x;
        s += x;
    }
    sort(a.begin(), a.end(), greater<int>());
    s %= k; 
    if(s == 0){
        cout << 0 << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        t += a[i];
        if(t >= s) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << n << "\n";
}

signed main(){
    solve();
    return 0;
}
