// 树状数组 + 离散化 + 逆序对
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n;
int a[N];

vector<int> all;

int tr[N];

int lowbit(int x){
    return x & -x;
}

int sum(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}

void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += v;
}

int getPos(int x){
    int l = 0, r = all.size() - 1;
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}

void solve(){
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        all.push_back(x); a[i] = x;
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()), all.end());
    int ans = 0;
    for(int i=n;i>=1;i--){
        int p = getPos(a[i]);
        ans += sum(p - 1);
        add(p, 1);
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    while(cin>>n){
        if(!n) break;
        all.clear(); for(int i=1;i<=n;i++) tr[i] = 0;
        solve();
    }
    return 0;
}
