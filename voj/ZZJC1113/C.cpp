#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
signed main(){
    int n; cin>>n;
    string a,b; cin>>a>>b;
    for(int i=0;i<n;i++)
        if(a[i] > b[i])
            swap(a[i],b[i]);
    auto get = [&](string &s){
        int res = 0;
        for(int i=0;i<n;i++)
            res = (res * 10 + s[i] - '0') % mod;
        return res;
    };
    cout << get(a) * get(b) % mod << "\n";
    return 0;
}
