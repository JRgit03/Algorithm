#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 5e5 + 10;
int n,k;
int a[N];
int st[N];
int l[N],r[N];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n+1;i++) {
        l[i] = i - 1;
        r[i] = i + 1;
    }
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    for(int i=1;i<=n;i++) heap.push({a[i], i});
    
    while(k > 0){
        auto [v, id] = heap.top(); heap.pop();
        //cout << id << " " << v << "\n";
        if(a[id] != v) continue;
        k -= 1;
        int x = id; st[x] = 1;
        a[l[x]] += a[x];
        a[r[x]] += a[x];
        r[l[x]] = r[x];
        l[r[x]] = l[x]; 
        if(l[x] >= 1 && l[x] <= n) heap.push({a[l[x]], l[x]});
        if(r[x] >= 1 && r[x] <= n) heap.push({a[r[x]], r[x]});
    }

    for(int i=1;i<=n;i++)
        if(!st[i])
            cout << a[i] << " ";
}

signed main(){
    solve();
    return 0;
}
// 数列中最小的整数 会 变化！！！ 因此用堆维护