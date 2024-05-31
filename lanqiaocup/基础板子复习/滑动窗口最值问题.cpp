#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;
int n,k;
int a[N];
int q[N],hh,tt;

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    // 滑窗最小值
    hh = 0, tt = -1; for(int i=1;i<=n;i++){
        while(hh <= tt && i - q[hh] + 1 > k) hh += 1;
        while(hh <= tt && a[q[tt]] >= a[i]) tt -= 1;
        q[++tt] = i;
        if(i >= k) cout << a[q[hh]] << " ";
    } cout << "\n";
    // 滑窗最大值
    hh = 0, tt = -1; for(int i=1;i<=n;i++){
        while(hh <= tt && i - q[hh] + 1 > k) hh += 1;
        while(hh <= tt && a[q[tt]] <= a[i]) tt -= 1;
        q[++tt] = i;
        if(i >= k) cout << a[q[hh]] << " ";
    } cout << "\n";
} 

signed main(){
    IOS;
    solve();
    return 0;
}
