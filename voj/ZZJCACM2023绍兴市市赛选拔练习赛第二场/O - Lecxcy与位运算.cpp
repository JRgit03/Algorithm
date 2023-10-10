#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e6 + 10 , Mod = 998244353;
int n,ans;
int a[N];
int cnt[31][2];

signed main(){
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            int t = (a[i] >> j) & 1;
            cnt[j][t] += 1;
            ans = (ans + cnt[j][1-t] * (1<<j)) % Mod;
        }
    }
    cout << ans << "\n";
    return 0;
}
