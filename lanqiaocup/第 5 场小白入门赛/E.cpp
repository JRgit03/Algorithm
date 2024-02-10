#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    int a = sqrt(n);
    int ans = 0;
    ans += 4 * 2 + 4 * (a - 2) * 3 + (a * a - 4 * a + 4) * 4;
    // cout << a << " " << ans << "\n"; 
    n -= a * a;
    if(n == 2 * a + 1){
        ans += 2 * (2 + (a - 1) * 4) + 4;
    }else{
        if(n >= a){
            ans += 2 + (a - 1) * 4;
            n -= a;
            if(n){
                ans += 2 + (n - 1) * 4;
            }
        }else if(n) {
            ans += 2 + (n - 1) * 4;
        }
    }
    cout << ans << "\n";
    return 0;
}
