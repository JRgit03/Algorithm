#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10, mod = 1e9 + 7;

// 枚举边长 找规律
// N * N点阵 => (N - 1) * (N - 1)正方形
// 边长为i的正方形 有i-1中内嵌正方形和1种正方形 => i,i
// 对于边长为i的正方形在边长为n-1的正方形有 (n - 1 - i + 1) * (n - 1 - i + 1) 选择
void solve(){
    int n; cin>>n;
    n -= 1;
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans = (ans + i * (n - i + 1) % mod * (n - i + 1) % mod) % mod;
    }
    cout << (ans % mod + mod) % mod << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
