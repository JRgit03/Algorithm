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

void solve(){
    int n,m; cin>>n>>m;
    // 当前行第num块,块内第pos位置
    function<int(int,int,int,int,int)> dfs = [&](int i,int l,int r,int pos,int num) -> int {
        debug(i, pos, num);
        if(i == 0) return pos;
        int len = r - l + 1;
        if(num & 1) return dfs(i-1,l-len+1,r,2*pos+1,num/2);
        return dfs(i-1,l,r+len-1,2*pos,num/2);
    }; 
    while(m--){
        int x; cin>>x;
        cout << dfs(n,x,x,0,x) << "\n";
    }
}
signed main(){
    IOS;
    solve();
    return 0;
}
