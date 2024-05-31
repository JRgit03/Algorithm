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
int n;
double l,r;
double a[N];

double f(double x){
    double res = 0;
    for(int i=1;i<=n+1;i++) res = res * x + a[i];
    return res;
}

void solve(){
    cin>>n>>l>>r;
    for(int i=1;i<=n+1;i++) cin>>a[i];
    for(int i=0;i<100;i++){
        double k = (r - l) / 3.0;
        double lmid = l + k, rmid = r - k;
        if(f(lmid) <= f(rmid)) l = lmid;
        else r = rmid;
    }
    printf("%.10lf\n", r);
}

signed main(){
    // IOS;
    solve();
    return 0;
}
