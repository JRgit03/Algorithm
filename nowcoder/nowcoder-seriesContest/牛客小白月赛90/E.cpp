// https://ac.nowcoder.com/acm/contest/view-submission?submissionId=68648420&returnHomeType=1&uid=233332217
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10, INF = 1e18;
int n,q;
int a[N],b[N],s[N];

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i] += s[i - 1] + a[i];
    }    
    for(int i=1;i<=n;i++) cin>>b[i];
    while(q--){
        int k; cin>>k;
        priority_queue<int> heap;
        int sa = 0, sb = 0, ans = INF;
        for(int i=1;i<=n;i++){
            sa += a[i];
            while(heap.size() >= k && heap.top() >= b[i]) {
                sb -= heap.top(); heap.pop();
            }
            if(heap.size() < k){
                heap.push(b[i]);
                sb += b[i];
            }
            if(heap.size() == k) ans = min(ans, sa + sb);
        }
        cout << ans << "\n";
    }
}

signed main(){
    solve();
    return 0;
}
