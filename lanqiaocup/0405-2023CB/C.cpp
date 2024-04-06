#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;
const int N = 1e4 + 10;
int n;
int a[N],b[N];

int check(int k){
    int suc = 1;
    for(int i=1;i<=n;i++) suc &= (a[i] / k >= b[i]);
    return suc;
}

int check2(int k){
    int suc = 1;
    for(int i=1;i<=n;i++) suc &= (a[i] / k <= b[i]);
    return suc;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int minv = -1, maxv = -1;
    int l = 1, r = 1e9;
    while(l < r){ // 二分答案最大值
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    maxv = r;
    l = 1, r = 2e9;
    while(l < r){ // 二分答案最小值
        int mid = (l + r) >> 1;
        if(check2(mid)) r = mid;
        else l = mid + 1;
    }
    minv = r;
    cout << minv << " " << maxv << "\n";
}

signed main(){
    IOS; solve();
    return 0;
} 

/*
3
75 3
53 2
59 2
*/

