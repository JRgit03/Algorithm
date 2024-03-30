#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, up = 1e6;
int tr[N];
int lowbit(int x) {
    return x & (-x);
}
void add(int x,int c){
    for(int i=x;i<=up;i+=lowbit(i)) tr[i] += c;
}
int sum(int x){
    int res = 0;
    for(int i=x;i>0;i-=lowbit(i)) res += tr[i];
    return res;
}

void solve(){
    int n; cin>>n;
    vector<array<int,2>> p(n);
    for(int i=0;i<n;i++) cin>>p[i][0]>>p[i][1];
    sort(p.begin(), p.end(), [&](auto &p, auto &q){
       return p[1] != q[1] ? p[1] < q[1] : p[0] < q[0]; 
    });
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        auto [x,y] = p[i];
        x += 1; y += 1;
        ans[sum(x)] += 1;
        add(x,1);
    }
    for(int i=0;i<n;i++) cout << ans[i] << "\n";
}

signed main(){
    solve();
    return 0;
}
