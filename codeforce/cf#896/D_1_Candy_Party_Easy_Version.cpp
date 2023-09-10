#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;

int findMaxBit(int x){
    int k = 0;
    while(x > 0){
        x >>= 1 , k++;
    }
    return 1 << (k-1);
}

void solve(){
    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;
    int sum = accumulate(a.begin(),a.end(),0L);
    if(sum % n != 0){
        cout << "No" << "\n";
        return;
    }
    int tar = sum / n;
    vector<int> v1,v2;
    for(int i=0;i<n;i++){
        int x = findMaxBit(a[i]);
        v1.push_back(x);
        a[i] -= x;
        v2.push_back(tar - a[i]);
    }
    sort(v1.begin(),v1.end()); 
    sort(v2.begin(),v2.end());
    cout << (accumulate(v1.begin(),v1.end(),0L) == accumulate(v1.begin(),v1.end(),0L) ? "Yes" : "NO") << "\n";
    return;
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
