#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1); for(int i=1;i<=n;i++) cin>>a[i];
    // 从第i堆到第j堆的硬币区间内 先手能拿到的最大值 每次只能操作当前最前面的和最后面的堆
    function<int(int,int)> dfs = [&](int i,int j) -> int {
        if(i == j) return a[i];
        if(i+1 == j) return  max(a[i],a[j]);
        return max(a[i] + min(dfs(i+2,j),dfs(i+1,j-1)) , a[j] + min(dfs(i+1,j-1),dfs(i,j-2)));
    };
    cout << dfs(1,n) << "\n";
}

int main(){
    IOS; solve();
    return 0;
}
