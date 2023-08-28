#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.begin(),v.end(),greater<int>());
    if(v[0]==0){
        cout << "0" << "\n";return;
    }
    for(int i=0;i<n;i++){
        if(i+1<n && i+1 >= v[i+1]){
            cout << i+1 << "\n";return;
        }
    }
    cout << -1 << "\n";return;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
