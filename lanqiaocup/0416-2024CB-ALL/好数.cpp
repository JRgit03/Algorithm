#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int f1 = 1, f2 = 1;
        int x = i, t = 1;
        while(x){
            int c = x % 10; x /= 10;
            if(t & 1) f1 &= (c & 1);
            else f2 &= ((c + 1) & 1);
            t += 1;
        }
        ans += (f1 && f2);
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
} 
