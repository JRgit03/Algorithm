#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];
    map<int,int> cnt;
    int t = n;
    while(k--){
        if(b[t] > n){
            cout << "No" << "\n";
            return;
        }
        cnt[t]++;
        if(cnt[t] > 1){
            cout << "Yes" << "\n";
            return;
        }
        t = (t - b[t] + n) % n;
        if(t == 0) t = n;
    } 
    cout << "Yes" << "\n";
    return;
}

int main(){
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}
