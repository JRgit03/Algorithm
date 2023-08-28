#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    vector<int> v(n*m);
    for(int i=0;i<n*m;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int min1 = v[0] , min2 = v[1];
    reverse(v.begin(),v.end());
    int maxx = v[0];
    
    int res = maxx * (n*m-1) - (n-1) * min1 - (m-1) * min2 - (n-1) * (m-1) * min1;
    res = max(res,maxx * (n*m-1) - (n-1) * min2 - (m-1) * min1 - (n-1) * (m-1) * min1);

    int max1 = v[0] , max2 = v[1];
    reverse(v.begin(),v.end());
    int minn = v[0];
    res = max(res , - minn * (n*m-1) +  (n-1) * max1 + (m-1) * max2 + (n-1) * (m-1) * max1);
    res = max(res , - minn * (n*m-1) +  (n-1) * max2 + (m-1) * max1 + (n-1) * (m-1) * max1);

    cout << res << "\n";
}

signed main(){int t;cin>>t;while(t--)solve();return 0;}
