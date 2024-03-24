#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int n;
int a[N],c[N];
int s[N];

int r[N]; // r[i] 右边第一个大于a[i]的a[j]下标
int stk[N],tt;

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++) s[i] += s[i-1] + c[i]; 
    tt = 0; for(int i=n;i>=1;i--){ 
        while(tt > 0 && a[stk[tt]] <= a[i]) tt -= 1;
        r[i] = (tt > 0 ? stk[tt] : n+1);
        stk[++tt] = i;
    }        
    // for(int i=1;i<=n;i++) cout << r[i] << " \n"[i == n]; 
    int ans = 0, sum = 0;
    for(int i=1;i<=n;i++){
        int j = r[i] - 1;
        int d = (s[j] - sum + a[i] - 1) / a[i];
        ans += d;
        sum += d * a[i];
        i = j;
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
