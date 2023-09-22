#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,maxk;
int a[N];
int h[N];
int q[N],hh,tt;

void solve(){
    cin>>n>>maxk;
    
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>h[i];
    
    int maxlen = 0;
    for(int i=1;i<=n;i++){
        int j=i;
        while(j+1<=n && h[j] % h[j+1] == 0) j++;
        int s=0;
        hh = 1 , tt = 0;        
        for(int k=i;k<=j;k++){
            s += a[k]; q[++tt] = k;
            while(hh<=tt && s > maxk) s -= a[q[hh++]];
            maxlen = max(maxlen,tt-hh+1);
        }
        i = j;
    }
    cout << maxlen << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
