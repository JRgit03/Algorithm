#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n,m;
int l[N],r[N];

// 暴力算法 O(nm)
void solve1(){
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for(int i=1;i<=m;i++){
        int L,R; cin>>L>>R;
        int ans = 0;
        for(int i=1;i<=n;i++){
            int len = r[i] - l[i];
            int x = max(L, l[i]), y = min(R, r[i]);
            if(x >= y) continue;
            if((y - x) * 2 >= len) ans += 1;
        }
        cout << ans << "\n";
    }    
}

// max{ri-li} <= min(Ri-Li) => 查询区间只要覆盖线段中点,必定至少覆盖一半
// 原问题等价于 给定m个询问LR,求区间内线段中点个数 细节处理小数
// 求中点是 (a + b) / 2
void solve2(){
    vector<int> p(n);
    for(int i=0;i<n;i++) {
        cin>>l[i]>>r[i]; l[i] *= 2, r[i] *= 2;
        p[i] = (l[i] + r[i]) / 2;
    }
    sort(p.begin(), p.end()); // 二分要求有二段性
    for(int i=1;i<=m;i++){
        int L,R,x,y; cin>>L>>R; L *= 2, R *= 2;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(p[mid] >= L) r = mid;
            else l = mid + 1;
        }
        if(p[r] >= L) x = r;
        else x = -1;

        l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(p[mid] <= R) l = mid;
            else r = mid - 1;
        }  
        if(p[r] <= R) y = r;
        else y = -1;

        if(x == -1 && y == -1) cout << 0 << "\n";
        else cout << y - x + 1 << "\n";
    }    
}

void solve(){
    cin>>n>>m;
    if(n * m <= 100000000) solve1();
    else solve2();
}

signed main(){
    IOS;
    solve();
    return 0;
}
