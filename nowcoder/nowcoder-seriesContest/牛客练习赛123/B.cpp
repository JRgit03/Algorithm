#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
int l[N],r[N];

void solve(){
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    for(int i=0;i<=n+1;i++) l[i] = r[i] = 0;
    for(int i=1;i<=n;i++) l[i] = max(l[i-1], a[i]);
    for(int i=n;i>=1;i--) r[i] = max(r[i+1], a[i]);
    for(int i=1;i<=n;i++){
        int maxV = max(l[i-1], r[i+1]);
        if(sum - maxV - a[i] >= maxV){
            int c = (sum - maxV - a[i] - maxV) & 1;
            if(a[i] > c) cout << 1 << " ";
            else cout << 0 << " ";
        }else{
            int c = maxV - (sum - maxV - a[i]);
            if(a[i] > c) cout << 1 << " ";
            else cout << 0 << " ";
        }
    }
    cout << "\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
