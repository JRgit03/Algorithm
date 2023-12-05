#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 20;
int n,k,ans;
int h[maxn];

int calc(){
    vector<int> l(n+2),r(n+2);
    for(int i=1;i<=n;i++) l[i] = max(l[i-1],h[i]);
    for(int i=n;i>=1;i--) r[i] = max(r[i+1],h[i]);
    int sum = 0;
    for(int i=1;i<=n;i++) sum += max(min(l[i-1],r[i+1]) - h[i],0LL);
    return sum;
}

void dfs(int i,int re){
    if(i == n+1 || re == 0){
        ans = max(ans,calc());
        return;
    }
    for(int j=0;j<=re;j++){
        h[i] += j;
        dfs(i+1,re-j);
        h[i] -= j;
    }    
}

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>h[i];
    dfs(1,k); cout << ans << "\n";
    return 0;
}
