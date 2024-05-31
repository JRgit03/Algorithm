#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10, maxn = 1e6;
int n;
int a[N];
int b[N];

// O(1e6 * 30)
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans = n;
    for(int i=1;i<=maxn;i++){ // 枚举a[1]的值
        for(int i=1;i<=min(30, n);i++) b[i] = -1;
        b[1] = b[2] = i;
        for(int i=3;i<=min(30, n);i++){
            b[i] = b[i - 1] + b[i - 2];
            if(b[i] > maxn) break;
        }
        int res = 0;
        for(int i=1;i<=min(30, n);i++){
            if(b[i] != a[i]) res += 1;
        }
        res += max(0, n - 30);
        ans = min(ans, res);
    }    
    cout << ans << "\n";
}

signed main(){
    // a[1] = a[2] = 1;
    // for(int i=3;i<=50;i++) {
    //     a[i] = a[i - 1] + a[i - 2];
    //     cout << i << " " << a[i] << "\n";
    // }
    IOS;
    solve();
    return 0;
}
