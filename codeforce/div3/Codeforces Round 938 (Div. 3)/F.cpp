#include <bits/stdc++.h>
#define int long long
using namespace std;

//如果序列中所有数字的按位异或为零 => 鲍勃获胜 异或为0 各数字出现偶数次
void solve(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    int ans = a/2 + b/2 + c/2 + d/2;
    if((a&1) && (b&1) && (c&1)) ans += 1;
    cout << ans << "\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
