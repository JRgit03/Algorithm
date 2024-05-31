#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e5 + 10;
int n;
int a[N];
int s[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        s[i] = s[i-1] + a[i];
    }  
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(i == 1) ans = max(ans, abs((s[n] - s[1]) - s[1]));
        else if(i == n) ans = max(ans, abs(s[n-1] - a[n]));
        else {
            int lsum = s[i - 1], rsum = s[n] - s[i];
            vector<int> vec = {a[i], lsum, rsum};
            sort(vec.begin(), vec.end());
            ans = max(ans, vec[2] - vec[0]);
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
