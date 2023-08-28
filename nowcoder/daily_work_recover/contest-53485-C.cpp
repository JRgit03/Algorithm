#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;cin>>n;
    vector<int> vec(n+1);
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++) cin>>vec[i];
    ll res = 0;
    for(int k=1;k<=n;k++){
        int x = vec[k];
        for(int i=2;i<=x/i;i++)
            if(x%i==0){
                while(x%i==0)x/=i;
                res += 1LL * (n-k+1) * (k - mp[i]);
                mp[i] = k;
            }
        if(x>1) {
            res += 1LL * (n-k+1) * (k - mp[x]);
            mp[x] = k;
        }
    }
    printf("%lld\n",res);
}

int main(){
    int t;cin>>t;   
    while(t--)solve();
    return 0;
}
