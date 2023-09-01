#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,m,k;
int st[N],ed[N];
int in[N],out[N];

signed main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        cin>>st[i]>>ed[i];
        in[ed[i]]++;
        out[st[i]]++;
    }
    int ans = 0 , sum = 0;
    for(int i=1;i<=n;i++){
        sum = sum - in[i] + out[i];
        ans = max(ans , (sum + k - 1) / k);
    }
    cout << ans << "\n";
    return 0;
}
