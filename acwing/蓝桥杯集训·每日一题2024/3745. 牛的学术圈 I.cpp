// 二分写法
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[N];

// 她只能引用每篇她的论文至多一次

int check(int k){
    int ne = 0, suc = 1;
    for(int i=1;i<=k;i++){
        if(a[i] >= k) continue;
        else if(a[i] + 1 == k) ne += 1;
        else suc = 0;
    }
    return m >= ne && suc; 
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    int l = 0, r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }    
    cout << r << "\n";
}

signed main(){
    solve();
    return 0;
}
