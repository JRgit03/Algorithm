#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 2e5 + 10;
int n,m;
int a[N];
int b[N];

int check(int k){
    int suc = 1, sum = 0;
    for(int i=1;i<=n;i++){
        if(a[i] >= k) continue;
        if(k - a[i] > b[i]) suc = 0;
        sum += k - a[i];
    }
    return (suc && sum <= m);
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int l = 0, r = 1e9;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
