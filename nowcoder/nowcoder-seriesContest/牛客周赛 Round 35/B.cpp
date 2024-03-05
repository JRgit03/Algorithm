#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    map<int,int> mp;
    for(int i=0;i<n*2;i++){
        int x; cin>>x;
        mp[x] += 1;
    }
    int suc = 1;
    vector<int> v1,v2;
    for(auto &[x, sz] : mp){
        if(sz & 1) suc = false;
        else{
            for(int i=0;i<sz/2;i++){
                v1.push_back(x);
                v2.push_back(x);
            }
        }
    }
    if(!suc) {
        cout << -1 << "\n";
        return 0;
    }
    for(auto &x : v1) cout << x << " "; cout << "\n";
    for(auto &x : v2) cout << x << " "; cout << "\n";
    return 0;
}
