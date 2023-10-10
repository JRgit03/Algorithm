#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;

int lowbit(int x){
    return x & (-x);
}

// 判断x是否为2的幂次
int check(int x){
    return lowbit(x) == x;
}

void solve(){
    int n,m; cin>>n>>m;
    n %= m;
    if(!check(m / __gcd(n,m))){
        cout << -1 << "\n";
        return;
    }
    int ans = 0;
    while(n){ // 模拟
        ans += n; 
        n = (n<<1) % m;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
