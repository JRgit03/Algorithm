 /**
 * 思维
 * https://atcoder.jp/contests/abc209/tasks/abc209_c
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10 ,Mod = 1e9 + 7;
int n;
int c[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    int ans = 1;
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++) ans = 1LL * ans * max(0,c[i]-i+1) % Mod;
    cout << ans << "\n";
    return 0;
}
