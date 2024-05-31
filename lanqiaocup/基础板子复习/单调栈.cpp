#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10;


// 单调栈：解决左右第一个大于或小于的元素/下标
// 以左边第一个小于ai的元素为例
int n;
int a[N];
int stk[N],tt;
int l[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    tt = 0;
    for(int i=1;i<=n;i++){
        while(tt > 0 && a[stk[tt]] >= a[i]) tt -= 1;
        l[i] = (tt > 0 ? a[stk[tt]] : -1);
        stk[++tt] = i;
    }
    for(int i=1;i<=n;i++) cout << l[i] << " ";
}

signed main(){
    IOS;
    solve();
    return 0;
}
