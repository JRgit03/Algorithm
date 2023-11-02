/**
 * 推式子
 * https://atcoder.jp/contests/abc194/tasks/abc194_c 
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int n;
int a[N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans = 0;
    for(int i=1;i<=n;i++) ans += (i - 1 + n - i) * a[i] * a[i];
    int pre = a[1]; // 1~i-1的前缀和
    for(int i=2;i<=n;i++) ans -= 2 * pre * a[i] , pre += a[i];
    cout << ans << "\n"; 
    return 0;
}
