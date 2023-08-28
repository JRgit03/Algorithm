#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int p;cin>>p;
    vector<ll> vec(p+1,1);
    for(int i=1;i<p;i++){
        if(i==1)vec[i]=1;
        else vec[i] = (vec[i] + vec[p%i]) % p;
        //cout << vec[i] << "\n";
    }
    ll res = 0;
    for(int i=1;i<p;i++)
        res += vec[i];
    //cout << res << "\n";
    printf("%.10lf\n",res*1.0/(p-1));
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
