/**
 * A
 * https://atcoder.jp/contests/abc180/tasks/abc180_c 
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> ans;
    for(int i=1;i*i<=n;i++){ // O(sqrt(n))
        if(n % i == 0){
            ans.push_back(i);
            if(i != n/i) ans.push_back(n/i);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x : ans) cout << x << "\n";
    return 0;
}

