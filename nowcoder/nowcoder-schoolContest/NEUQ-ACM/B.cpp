#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    double p = 1, ans = 0; 
    for(int k=1;;k++){
        n -= 2;
        if(n < 5) break;
        ans += p * 0.03;
        p *= (1 - 0.03);
    }
    printf("%.10lf\n", ans);
}

signed main(){
    solve();
    return 0;
}
