#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int RMAX = 1e18;

int calc(int n,int r){ // n的r进制表示
    int res = 0;
    while(n){
        res += n % r;
        n /= r;
    }
    return res;
}

void solve(){
    int n,tar;cin>>n>>tar;

    int l=2,r=tar+1;
    while(l<r){
        int mid = l + r>> 1;
        if(calc(n,mid) >= tar) r = mid;
        else l = mid + 1;
    }
    if(calc(n,r) == tar) cout << r << "\n";
    else cout << -1 << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
