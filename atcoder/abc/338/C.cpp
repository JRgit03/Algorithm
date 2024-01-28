#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> q(n),a(n),b(n);
    for(int i=0;i<n;i++) cin>>q[i];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int ans = 0, k;
    k = 0; while(1){
        int t = INT_MAX;
        for(int i=0;i<n;i++){
            if(1LL * a[i] * k > q[i]){
                t = -1;
                break;
            }
            if(b[i] == 0) continue;
            t = min(t, (q[i] - a[i] * k) / b[i]);
        }
        if(t == -1) break;
        ans = max(ans, k + t);
        k++;
    }
    k = 0; while(1){
        int t = INT_MAX;
        for(int i=0;i<n;i++){
            if(1LL * b[i] * k > q[i]){
                t = -1;
                break;
            }
            if(a[i] == 0) continue;
            t = min(t, (q[i] - b[i] * k) / a[i]);
        }
        if(t == -1) break;
        ans = max(ans, k + t);
        k++;
    }
    cout << ans << "\n";
    return 0;
}
