#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
int a,b;
map<int,int> mp;

// 记忆化搜索
int dfs(int x){
    if(mp.count(x)) return mp[x];
    int ans = x - a; // +1 
    if(x / 2 >= a) ans = min(ans,dfs(x/2)+1+(x&1));
    int y = sqrt(x);
    if(y >= a) ans = min(ans,dfs(y)+1+x-y*y);
    return mp[x] = ans;
}

void solve(){
    cin>>a>>b;
    mp.clear(); mp[a] = 0; dfs(b);
    cout << mp[b] << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
