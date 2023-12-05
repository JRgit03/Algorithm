#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,l; cin>>n>>m>>l;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    vector<int> g[n+1];
    while(l--){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
    }
    typedef pair<int,int> PII;
    priority_queue<PII> heap; // {val,id}
    for(int i=1;i<=m;i++) heap.push({b[i],i});
    set<int> del;
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(auto j : g[i]) del.insert(j);
        queue<PII> que;
        while(heap.size() && del.count(heap.top().second)) {
            que.push(heap.top()); heap.pop();
        }
        if(heap.size()) ans = max(ans, heap.top().first + a[i]);
        for(auto j : g[i]) del.erase(del.lower_bound(j));
        while(que.size()) {
            auto it = que.front(); que.pop(); heap.push(it);
        }
    }
    cout << ans << "\n";
    return 0;
}
