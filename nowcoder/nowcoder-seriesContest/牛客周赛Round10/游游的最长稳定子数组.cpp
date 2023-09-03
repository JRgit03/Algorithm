#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;
    int ans = 0 , cur = 1;
    for(int i=1;i<n;i++){
        if(abs(a[i] - a[i-1]) <= 1) cur++;
        else cur = 1;
        ans = max(ans,cur);
    }
    cout << ans << "\n";
}

int main(){
    IOS;solve();
    return 0;
}
